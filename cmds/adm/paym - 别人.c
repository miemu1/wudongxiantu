// paym.c

#include <ansi.h>

int main(object me, string arg)
{
	string *str,username,userid,mid;
	mapping datas=([]);
	int i,type,amount,rmb;
	object ob,obj,mob,mobj;

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	seteuid(ROOT_UID);
	if(!arg||sscanf(arg,"%s %d",userid,rmb)!=2)
		return notify_fail("格式错误！！！\n");

	amount = rmb*10;

	if(rmb>=1000) amount += amount/5;
	else if(rmb>=500) amount += amount/10;
	else if(rmb>=1) amount += amount/20;

	//amount +=rmb;

	userid = lower_case(userid);
	if(!(obj=find_player(userid)))
	{
		ob = new(LOGIN_OB);
		ob->set("id",userid);
		ob->set("body", USER_OB);
		obj = LOGIN_D->make_body(ob);
		destruct(ob);
		if(obj->restore())
		{
			obj->setup();
			username = obj->query("name");
			obj->add("zjvip/all_pay",rmb);
			obj->add("yuanbao",amount);
			if(stringp(mid=obj->query("zjvip/master")))
			{
				if(!(mobj=find_player(mid)))
				{
					mob = new(LOGIN_OB);
					mob->set("id",mid);
					mob->set("body", USER_OB);
					mobj = LOGIN_D->make_body(mob);
					destruct(mob);
					if(mobj->restore())
					{
						mobj->setup();
						mobj->add("zjvip/dizi_pay",rmb);
						mobj->save();
					}
					destruct(mobj);
				}
				else if(mobj)
				{
					mobj->add("zjvip/dizi_pay",rmb);
					mobj->save();
				}
			}
			obj->save();
		}
		destruct(obj);
	tell_object(me,YEL"你给"+userid+"充值"+rmb+"元成功。。。
	"+userid+"目前不在游戏中。"NOR"\n");
	}
	else if(obj)
	{
		username = obj->query("name");
		obj->add("zjvip/all_pay",rmb);
		obj->add("yuanbao",amount);
		if(stringp(mid=obj->query("zjvip/master")))
		{
			if(!(mobj=find_player(mid)))
			{
				mob = new(LOGIN_OB);
				mob->set("id",mid);
				mob->set("body", USER_OB);
				mobj = LOGIN_D->make_body(mob);
				destruct(mob);
				if(mobj->restore())
				{
					mobj->setup();
					mobj->add("zjvip/dizi_pay",rmb);
					mobj->save();
				}
				destruct(mobj);
			}
			else if(mobj)
			{
				mobj->add("zjvip/dizi_pay",rmb);
				mobj->save();
			}
		}
		obj->save();
	tell_object(obj,YEL+me->query("name")+"给你充值"+chinese_number(rmb)+"元成功。。。
	你原有灵石"+chinese_number(obj->query("yuanbao")-amount)+"个。
	你现有灵石"+chinese_number(obj->query("yuanbao"))+"个。"NOR"\n");

	tell_object(me,YEL"你给"+userid+"充值"+rmb+"元成功。。。
	"+obj->query("name")+"目前正在游戏中。
	"+obj->query("name")+"原有灵石"+chinese_number(obj->query("yuanbao")-amount)+"个。
	"+obj->query("name")+"现有灵石"+chinese_number(obj->query("yuanbao"))+"个。"NOR"\n");
	}

	log_file("pay/paym", sprintf(me->query("id")+"在%s:给%s(%s)通过%s充值%d元。\n",ctime(time()),username,userid,"手动",rmb));
	VIP_D->add_paym(sprintf("%d",time()),(["id":userid,"num":rmb]));
	return 1;
}
