// GMCZtianji.c

#include <ansi.h>

int main(object me, string arg)
{
	string *str,username,userid,mid;
	mapping datas=([]);
	int i,type,amount,rmb;
	object ob,obj,mob,mobj;

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;
	if (sscanf(arg, "%s", userid ) == 1) 
write(INPUTTXT(HIY+ZJSIZE(22)+"你想给("+HIG+ZJSIZE(22)+(arg)+HIY+ZJSIZE(22)")充值多少天机？"NOR,"GMCZtianji "+arg+" $txt# ")+"\n");

	seteuid(ROOT_UID);
	if(!arg||sscanf(arg,"%s %d",userid,rmb)!=2)
		return notify_fail("正在充值！！！\n");

	amount = rmb*10;
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
			obj->add("tianji",amount);
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
		obj->add("tianji",amount);
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
	你原有天机"+chinese_number(obj->query("tianji")-amount)+"个。
	你现有天机"+chinese_number(obj->query("tianji"))+"个。"NOR"\n");

	tell_object(me,YEL"你给"+userid+"充值"+rmb+"元成功。。。
	"+obj->query("name")+"目前正在游戏中。
	"+obj->query("name")+"原有天机"+chinese_number(obj->query("tianji")-amount)+"个。
	"+obj->query("name")+"现有天机"+chinese_number(obj->query("tianji"))+"个。"NOR"\n");
	}

	log_file("pay/GMCZtianji", sprintf(me->query("id")+"在%s:给%s(%s)通过%s充值%d元。\n",ctime(time()),username,userid,"手动",rmb));
	VIP_D->add_GMCZtianji(sprintf("%d",time()),(["id":userid,"num":rmb]));
	return 1;
}
