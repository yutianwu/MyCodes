/*
	此类讲了使用sqlite的方法
*/

package com.example.vacant;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;

import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DBHelper {

	public static final String DBNAME = "mytime.db";	
	public static final String ITEMS = "items";			
	public static final String ACTS = "acts";			
	public static final int VERSION = 1;				
	public static SQLiteDatabase dbInstance;
	private MyDBHelper myDBHelper;
	private Context context;

	public DBHelper(Context context) {
		this.context = context;
	}

	public void openDatabase() {
		if (dbInstance == null) {
			myDBHelper = new MyDBHelper(context, DBNAME, VERSION);
			dbInstance = myDBHelper.getWritableDatabase();
		}
	}

	public long insertItem(Item item) {
		/**
		 * 添加事项
		 */
		ContentValues values = new ContentValues();
		values.put("name", item.name);
		values.put("description", item.description);
		return dbInstance.insert(ITEMS, null, values);
	}
	
	public long insertAct(Act act) {
		/**
		 * 添加活动
		 */
		ContentValues values = new ContentValues();
		values.put("name", act.name);
		values.put("description", act.description);
		values.put("start", act.start);
		values.put("predict", act.predict);
		values.put("end", act.start);
		values.put("status", "false");
		return dbInstance.insert(ACTS, null, values);
	}

	public ArrayList getAllItems() {
		/**
		 * 获得所有事项的详细信息
		 */
		ArrayList list = new ArrayList();
		Cursor cursor = null;
		cursor = dbInstance.query(ITEMS, new String[] { "_id",
				"name", "description"}, null,
				null, null, null, null);

		while (cursor.moveToNext()) {
			HashMap item = new HashMap();
			item.put("_id", cursor.getInt(cursor.getColumnIndex("_id")));
			item.put("name", cursor.getString(cursor.getColumnIndex("name")));
			item.put("description", cursor.getString(cursor.getColumnIndex("description")));
			list.add(item);
		}
		cursor.close();
		return list;
	}
	
	public ArrayList<String> getAllItemNames() {
		/**
		 * 得到所有事项的名字
		 */
		ArrayList<String> list = new ArrayList<String>();
		Cursor cursor = null;
		cursor = dbInstance.query(ITEMS, new String[] {"name"}, null,
				null, null, null, null);
		while (cursor.moveToNext()) {
			list.add(cursor.getString(cursor.getColumnIndex("name")));
		}
		cursor.close();
		return list;
	}

	public ArrayList getTodayActs() {
		/**
		 * 获得当天完成的活动
		 */
		ArrayList list = new ArrayList();
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd");
		String time = df.format(new Date());
		Cursor cursor = null;
		cursor = dbInstance.query(ACTS, new String[] { "_id",
				"name", "description", "start", "end", "span"},"status=?" + "AND start like ?",
				new String[] {"true", "%" + time + "%"}, null, null, null);
		while (cursor.moveToNext()) {
			HashMap act = new HashMap();
			act.put("_id", cursor.getInt(cursor.getColumnIndex("_id")));
			act.put("name", cursor.getString(cursor.getColumnIndex("name")));
			act.put("description", cursor.getString(cursor.getColumnIndex("description")));
			act.put("start", cursor.getString(cursor.getColumnIndex("start")));
			act.put("end", cursor.getString(cursor.getColumnIndex("end")));
			act.put("span", cursor.getString(cursor.getColumnIndex("span")));
			list.add(act);
		}
		cursor.close();
		return list;
	}
	
	public ArrayList getWeekActs() {
		/**
		 * 获得本周的活动
		 */
		ArrayList list = new ArrayList();
		Cursor cursor = null;
		String monday = this.getMonday();
		String weekend = this.getWeekend();
		String sql = "select * from ACTS where strftime('%Y-%m-%d', start)>=? and strftime('%Y-%m-%d',start)<=?";
		cursor = dbInstance.rawQuery(sql, new String[]{monday, weekend});
		while (cursor.moveToNext()) {
			HashMap act = new HashMap();
			act.put("_id", cursor.getInt(cursor.getColumnIndex("_id")));
			act.put("name", cursor.getString(cursor.getColumnIndex("name")));
			act.put("description", cursor.getString(cursor.getColumnIndex("description")));
			act.put("start", cursor.getString(cursor.getColumnIndex("start")));
			act.put("end", cursor.getString(cursor.getColumnIndex("end")));
			act.put("span", cursor.getString(cursor.getColumnIndex("span")));
			list.add(act);
		}
		cursor.close();
		return list;
	}
	
	public ArrayList getMonthActs() {
		/**
		 * 获得本月的活动
		 */
		ArrayList list = new ArrayList();
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM");
		String time = df.format(new Date());
		Cursor cursor = null;
		cursor = dbInstance.query(ACTS, new String[] { "_id",
				"name", "description", "start", "end", "span"},"status=?" + "AND start like ?",
				new String[] {"true", "%" + time + "%"}, null, null, null);
		while (cursor.moveToNext()) {
			HashMap act = new HashMap();
			act.put("_id", cursor.getInt(cursor.getColumnIndex("_id")));
			act.put("name", cursor.getString(cursor.getColumnIndex("name")));
			act.put("description", cursor.getString(cursor.getColumnIndex("description")));
			act.put("start", cursor.getString(cursor.getColumnIndex("start")));
			act.put("end", cursor.getString(cursor.getColumnIndex("end")));
			act.put("span", cursor.getString(cursor.getColumnIndex("span")));
			list.add(act);
		}
		cursor.close();
		return list;
	}
	
	public Act queryActNow () {
		/**
		 * 查询是否有未结束的活动
		 */
		Act act = new Act();
		Cursor cursor = null;
		cursor = dbInstance.query(ACTS, new String[] { "_id",
				"name", "description", "start", "predict"}, "status=?",
				new String[] {"false"}, null, null, null);
		while (cursor.moveToNext()) {
			act._id = cursor.getInt(cursor.getColumnIndex("_id"));
			act.name = cursor.getString(cursor.getColumnIndex("name"));
			act.description = cursor.getString(cursor.getColumnIndex("description"));
			act.start = cursor.getString(cursor.getColumnIndex("start"));
			act.predict = cursor.getString(cursor.getColumnIndex("predict"));
		}
		cursor.close();
		return act;
	}
	
	public void endActNow(String end, long min) {
		/**
		 * 设置当前活动结束
		 */
		ContentValues cv = new ContentValues();
		cv.put("end", end);
		cv.put("status", "true");
		cv.put("span", min);
		dbInstance.update(ACTS, cv, "status=?", new String[] {"false"});
	}
	
	public void delete(int _id) {
		System.out.println(_id);
		String id = _id + "";
		System.out.println(dbInstance.delete(ITEMS, "_id=?", new String[]{id}));
	}
	
	@SuppressLint("SimpleDateFormat")
	private String getMonday() {
		/**
		 * 获得周一的日期
		 */
		Calendar calendar = Calendar.getInstance();
		int day_of_week = calendar.get(Calendar.DAY_OF_WEEK) - 1;
		if (day_of_week == 0) {
			day_of_week = 7;
		}
		calendar.add(Calendar.DATE, -day_of_week + 1);
		SimpleDateFormat format =  new SimpleDateFormat("yyy-MM-dd");
		return format.format(calendar.getTime());
	}
	
	@SuppressLint("SimpleDateFormat")
	private String getWeekend() {
		/**
		 * 获得周日的日期
		 */
		Calendar calendar = Calendar.getInstance();
		int day_of_week = calendar.get(Calendar.DAY_OF_WEEK) - 1;
		if (day_of_week == 0)
			day_of_week = 7;
		calendar.add(Calendar.DATE, -day_of_week + 7);
		SimpleDateFormat format =  new SimpleDateFormat("yyyy-MM-dd");
		return format.format(calendar.getTime());
	}
	
	class MyDBHelper extends SQLiteOpenHelper {

		public MyDBHelper(Context context, String name, int version) {
			super(context, name, null, version);
		}

		@Override
		public void onCreate(SQLiteDatabase db) {
			String tableCreate = "create table "
					+ ITEMS
					+ " (_id integer primary key autoincrement,name text,description text)";
			db.execSQL(tableCreate);
			
			tableCreate = "create table "
					+ ACTS
					+ " (_id integer primary key autoincrement,start text, predict text, end text, name text, description text, span integer, status text)";
			db.execSQL(tableCreate);			
		}

		@Override
		public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
			String sql = "drop table if exists " + ITEMS;
			db.execSQL(sql);
			myDBHelper.onCreate(db);
		}
	}
}
