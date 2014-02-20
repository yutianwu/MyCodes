/*
	此类描述了使用百度定位api的方法，其他的细节配置参见文档
*/

package com.vote.activity;

import java.util.ArrayList;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.baidu.location.BDLocation;
import com.baidu.location.BDLocationListener;
import com.baidu.location.LocationClient;
import com.baidu.location.LocationClientOption;
import com.example.vote4.R;
import com.vote.pojo.Position;

import android.app.Activity;
import android.net.ParseException;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;

public class NearbyVoteActivity extends Activity implements OnClickListener
{
	public LocationClient mLocationClient = null;
	public BDLocationListener myListener = null;
	private Button bt_start = null;
	private Position pos = new Position();
	private ListView listView;
	private ArrayList<String> data = new ArrayList<String>();
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
	    mLocationClient = new LocationClient(getApplicationContext());     //声明LocationClient类
		mLocationClient.registerLocationListener(new BDLocationListener() {
			@Override
			public void onReceiveLocation(BDLocation location) {
				if (location == null)
					return ;
				pos.setLatitude(location.getLatitude());
				pos.setLongitude(location.getLongitude());
				getPoi();
				Log.e("Latitude", pos.getLatitude()+"");
			}

			@Override
			public void onReceivePoi(BDLocation poiLocation) {
				// TODO Auto-generated method stub
				if(poiLocation.hasPoi()){
					String poi = poiLocation.getPoi();
					poi = poi.substring(5, poi.length()-1);
					data.clear();
					try{
						JSONArray jArray = new JSONArray(poi);
					    JSONObject json_data=null;
					    for(int i=0;i<jArray.length();i++){
					    	json_data = jArray.getJSONObject(i);
					    	data.add(json_data.getString("name"));
					    	Log.e("name", json_data.getString("name"));
					    }
					} catch(JSONException e1) {
					} catch (ParseException e1) {
					      e1.printStackTrace();
					}
					setView();
				}
			}
		});
		setContentView(R.layout.activity_nearby_vote);
		
		start();
		bt_start = (Button) findViewById(R.id.start);
		bt_start.setOnClickListener(this);
	}   
	
	public void setView() {
		listView = (ListView) findViewById(R.id.listview);
        listView.setAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_expandable_list_item_1, data));
        mLocationClient.stop();
	}
	
	public void start() {
		Log.e("start", "start");
		
		setLocationOption();
		mLocationClient.start();
		
		Log.e("ISTART",mLocationClient.isStarted() + "");
	}

	public void getPoi() {
		mLocationClient.requestPoi();
	}
	
	
	@Override
	public void onDestroy() {
		mLocationClient.stop();
		super.onDestroy();
	}

	//设置相关参数
	private void setLocationOption(){
		LocationClientOption option = new LocationClientOption();
		option.setOpenGps(true);				//打开gps
		option.setCoorType("bd09ll");			//设置坐标类型
		option.setPriority(LocationClientOption.GpsFirst);        //不设置，默认是gps优先
		option.setServiceName("com.baidu.location.service_v2.9");
		//option.disableCache(true);	
		option.setPoiNumber(5);			//最多返回POI个数	
		option.setPoiDistance(1000); 	//poi查询距离		
		option.setPoiExtraInfo(true); 	//是否需要POI的电话和地址等详细信息	
		mLocationClient.setLocOption(option);
	}

	@Override
	public void onClick(View view) {
		// TODO Auto-generated method stub
		switch (view.getId()) {
			case R.id.start:
				start();
				break;
		}
	}
}