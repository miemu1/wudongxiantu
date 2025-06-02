// usersd.c

#include <ansi.h>
#include <mudlib.h>
#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

mapping vips;
mapping qiandao;
mapping paym;
mapping vdata;
mapping daoshi;
mapping tgy;	//�����Ϊ�ƹ�Ա��ID�Լ���ȯ�洢
string *tg_ip; 	//��д�ƹ����IP�洢

void create()
{
	seteuid(ROOT_UID);
	if( !restore() )
	{
		vips= ([]);
		qiandao = ([]);
		vdata = ([]);
		paym = ([]);
		daoshi = ([]);
	}
	if( !mapp(vips) )
		vips = ([]);
	if( !mapp(qiandao) )
		qiandao = ([]);
	if( !mapp(vdata) )
		vdata = ([]);
	if( !mapp(paym) )
		paym = ([]);
	if( !mapp(daoshi) )
		daoshi = ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "vipd"; }

int add_order(string name)
{
	if( undefinedp(vips["order"]) ) vips["order"]=({});
	vips["order"] += ({name});
	save();
	return 1;
}

int delete_order(string name)
{
	vips["order"] -= ({name});
	save();
	return 1;
}

mixed set_vips(string prop, mixed data)
{
	if( !mapp(vips ) ) vips = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( vips , explode(prop, "/"), data );

	return vips[prop] = data;
}

mixed query_vips(string prop)
{
	mixed data;

	if( !mapp(vips) ) return 0;

	if( undefinedp(vips[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(vips, explode(prop, "/"));
	else
		data = vips[prop];

	return data;
}

mixed set_daoshi(string prop, mixed data)
{
	if( !mapp(daoshi ) ) daoshi = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( daoshi , explode(prop, "/"), data );

	return daoshi[prop] = data;
}

int delete_query_qian(string prop)
{
	if( !mapp(daoshi) ) return 0;

	if( (strsrch(prop, '/')!=-1) )
		return _delete(daoshi, explode(prop, "/"));
	else
	{
		map_delete(daoshi,prop);
		return 1;
	}
}

string *list_daoshi()
{
	mixed data;

	if( !mapp(daoshi) ) return 0;

	return keys(daoshi);
}

mixed query_daoshi(string prop)
{
	mixed data;

	if( !mapp(daoshi) ) return 0;

	if( undefinedp(daoshi[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(daoshi, explode(prop, "/"));
	else
		data = daoshi[prop];

	return data;
}

mixed set_qian(string prop, mixed data)
{
	if( !mapp(qiandao ) ) qiandao = ([]);

	if(intp(data)&&data > 3000 && strsrch(prop,"/jf_used")==-1)
		data = 3000;
	if( strsrch(prop, '/')!=-1 )
		return _set( qiandao , explode(prop, "/"), data );

	return qiandao[prop] = data;
}

mixed query_qian(string prop)
{
	mixed data;

	if( !mapp(qiandao) ) return 0;

	if( undefinedp(qiandao[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(qiandao, explode(prop, "/"));
	else
		data = qiandao[prop];

	return data;
}

string *list_qian()
{
	mixed data;

	if( !mapp(qiandao) ) return 0;

	return keys(qiandao);
}

int delete_qian(string prop)
{
	if( !mapp(qiandao) ) return 0;

	if( (strsrch(prop, '/')!=-1) )
		return _delete(qiandao, explode(prop, "/"));
	else
	{
		map_delete(qiandao,prop);
		return 1;
	}
}
mixed set_paym(string prop, mixed data)
{
	if( !mapp(paym) ) paym = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( paym , explode(prop, "/"), data );

	return paym[prop] = data;
}

mixed query_paym(string prop)
{
	mixed data;

	if( !mapp(paym) ) return 0;

	if( undefinedp(paym[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(paym, explode(prop, "/"));
	else
		data = paym[prop];

	return data;
}

int add_paym(string t,mapping paym)
{
	set_paym(t,paym);
	save();
	return 1;
}

int save_vdata(object me)
{
	vdata[me->query("id")] = ([]);
	vdata[me->query("id")]["yuanbao"] = me->query("yuanbao");
	vdata[me->query("id")]["vipgift"] = me->query("zjvip/vipgift");
	vdata[me->query("id")]["all_pay"] = me->query("zjvip/all_pay");
	vdata[me->query("id")]["tap_pinglun"] = me->query("tap_pinglun");	
	save();
	return 1;
}

int restore_vdata(object me)
{
	if(undefinedp(vdata[me->query("id")])) return 1;

	me->set("yuanbao",vdata[me->query("id")]["yuanbao"]);
	me->set("zjvip/vipgift",vdata[me->query("id")]["vipgift"]);
	me->set("zjvip/all_pay",vdata[me->query("id")]["all_pay"]);
	me->set("tap_pinglun",vdata[me->query("id")]["tap_pinglun"]);	
	map_delete(vdata,me->query("id"));
	save();
	return 1;
}


//�����Ϊ�ƹ�Ա
int set_tgy(object player)
{
	string tgy_id;
	if(!player || !userp(player)) return 0;
		
	tgy_id = player->query("id");
	
	
	if(!tgy) tgy = ([ tgy_id:(["jf_all":0,"jf_use":0]) ]);
	else if(!tgy[tgy_id] )
		tgy += ([ tgy_id:(["jf_all":0,"jf_use":0]) ]);
	else return -1;
	this_object()->save();
	return 1;
}

//��ѯ�ƹ�Ա
mapping query_tgy(string tgy_id)
{
	if(!tgy) return 0;
	else return tgy[tgy_id];
}

//�º���д�ƹ��룬��ý���
void use_tgm(string tgy_id,object player)
{
	mapping jfs;
	object ob ;
	string ip = query_ip_number(player);
	if(player->query("combat_exp") < 1500000)
		return tell_object(player,"��Ϊ150w������д��\n");
	if(!tgy || !(jfs = tgy[tgy_id]) ) return ;
	
	if(sizeof(tg_ip)>0 && member_array(ip,tg_ip) != -1) 
	{
		tell_object(player,"ͬһ��IP��ַֻ�ܻ��һ���ƹ������\n");
		return;
	}
	
	// 

	jfs["jf_all"] += 10000; //��д�ƹ���������ƹ�Ա�ĵ�ȯ
	tgy[tgy_id] = jfs;
	if(!tg_ip) tg_ip = ({ip});
	else tg_ip += ({ip});
	this_object()->save();
	
	ob = new("clone/gift/tg_gift");//�ƹ��������
	ob->move(player);
	tell_object(player,"��д�ƹ���ɹ������������"+ob->name()+"��\n");
	player->set("tgy_id",tgy_id);
}

//��ȯ�һ���ʯ����
int tgy_convert(object tgy_ob,int tx_num)
{
	mapping jfs;
	int num1,num2;
	string tgy_id = tgy_ob->query("id");
	if(!tgy || !(jfs = query_tgy(tgy_id)) ) return -1;//û������ƹ�Ա
	num1 = jfs["jf_all"];
	num2 = jfs["jf_use"];
	if(num1 - num2 < tx_num) //ʣ���ȯ����
	return -15;
	jfs["jf_use"] += tx_num;
	tgy[tgy_id] = jfs;
	this_object()->save();
	tx_num = tx_num*3/2;// ��ȯ:��ʯ�Ķһ�����(10:1)
	tgy_ob->add("yuanbao",tx_num);
	return tx_num;
}

//�޸ĵ�ȯ����
int add_tgy_jf(string tgy_id,int tx_num)
{
	mapping jfs;
	int num1,num2;
	if(!tgy || !(jfs = query_tgy(tgy_id)) ) return -1;//û������ƹ�Ա
	if(tx_num < 0)
	{//�۳���ȯ
		tx_num = abs(tx_num);
		num1 = jfs["jf_all"];
		num2 = jfs["jf_use"];
		if(num1 - num2 < tx_num) //ʣ���ȯ����
			return -15;
		jfs["jf_use"] += tx_num;
	}
	else//���ӵ�ȯ
		jfs["jf_all"] += tx_num;

	tgy[tgy_id] = jfs;
	this_object()->save();
	return tx_num;
}

//���ù��ܣ�������Ȩ�޿���
void reset_tg(object wiz)
{
	tgy = 0;
	tg_ip = 0;
	wiz->delete("tgy_id");
	tell_object(wiz,"��ǰ�ƹ��Ѿ����ã�����ƹ�����Ҳ�����\n");
	this_object()->save();
	wiz->save();
}
