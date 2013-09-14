/*
	此类讲了listview的使用
*/

package com.yutian.locate;

import java.util.ArrayList;
import java.util.HashMap;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ListView;
import android.widget.SimpleAdapter;

public class ViewContactsActivity extends Activity implements OnItemClickListener{
	private ListView listView;
    private DBUtils db;
    private ArrayList personList = new ArrayList();
    private int personid;
    
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_add_contact);
		initView();
	}

	public void initView() {
		db = new DBUtils(this);
		personList = db.getPersons();
		
		listView = new ListView(this);
		SimpleAdapter adapter = new SimpleAdapter(this, personList ,R.layout.item_person,
                new String[]{"name","phone"},
                new int[]{R.id.name,R.id.phone});
		listView.setAdapter(adapter);
		listView.setOnItemClickListener(this);
        setContentView(listView);
	}
	
	@Override
	public void onItemClick(AdapterView<?> arg0, View arg1, int pos,
			long arg3) {
		HashMap item = (HashMap) arg0.getItemAtPosition(pos);
		personid = Integer.parseInt(String.valueOf(item.get("_id")));
		new AlertDialog.Builder(this).setPositiveButton(
				"确定", new DialogInterface.OnClickListener() {
					@Override
					public void onClick(DialogInterface dialog,
							int which) {
						deletePerson();
						initView();
					}
				}).setNegativeButton("取消",
				new DialogInterface.OnClickListener() {
					@Override
					public void onClick(DialogInterface dialog,
							int which) {
					}
				}).setTitle("是否要删除?").create().show();
	}
	
	public void deletePerson() {
		db = new DBUtils(this);
		db.deletePerson(personid);
		
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
}