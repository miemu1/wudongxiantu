// xiantong.c
#include <ansi.h>

inherit NPC;
inherit F_DTIME;

#define MEMBER_D              "/adm/daemons/memberd"
#define DB_D                  "/adm/daemons/dbd"

string gift_jingyan();
string gift_neigong();
string gift_ultra();
string gift_pthuiyuan();
string gift_zshuiyuan();


void create()
{
    	set_name(HIY "��������" NOR, ({ "fuxing laoren", "fuxing", "laoren" }));
	set("nickname", HIG "ӭ��ʹ��" NOR);
	set("title", "");
   	set("long", "�����䶯��;����ӭ��ʹ�ߣ����������ķ��š�\n");
    	set("gender", "����");
    	set("age", 999);
	set("max_qi", 99999);
	set("qi", 99999);
	set("max_jingli", 99999);
	set("max_jing", 99999);
	set("max_neili", 99999);
	set("jing", 99999);
	set("jingli", 99999);
	set("neili", 99999);

	set("per", 28);
	set("con", 88);
	set("int", 88);
	set("dex", 88);
	set("str", 88);

        set_disappear_msg("\n��ֻ������ǰһ��������һ�������������Ѿ������ˡ�\n");
        set_appear_time(([
	        "2,7," : "3,7,",
        ]));
	
	set("inquiry", ([ 
		"�䶯��;"    : "�䶯��;���䶯��;ϵͳ�ռ��汾��ϣ���������졣\n",
		"����"          : "�����䶯��;�ͷ�NPC���Ժ�����ָ�̣�\n",
		"lonely"        : "Lonely�㶼����ʶ�����ǻ�ȥ���������ɣ�\n",
		"��������"      : "��ĥĥ��䣬������ʲô�¿�˵�ɣ�\n",
                "ÿ�ս���"      : "ÿ�ս�����������ʹ������ȡ��\n",
                "��Ϊ����"      : (: gift_jingyan :),
                "�ڹ�����"      : (: gift_neigong :),
                "��ʦ����"      : (: gift_ultra :),
                "��ͨ��Ա����"  : (: gift_pthuiyuan :),
                "�����Ա����"  : (: gift_zshuiyuan :),
	]));

    	set("combat_exp", 10000000);
    	set("shen_type", 1);
    	setup();
}

string gift_jingyan()
{
	object me, ob;
	
	if (! objectp(me = this_player()))return "";
	
	if (query("kaifu_huodong/gift_jingyan", me))
		return me->name() + NOR "���Ѿ���ȡ���ý����ˣ�";
	
	if (query("combat_exp", me) < 8880000)
	{
		return me->name() +  NOR "����Ϊ����888�򣬲��ܲ���û��\n";
	}
	
	// ֻ����ǰ100�������ȡ
	if (DB_D->query_data("kaifu_huodong/gift_jingyan/count") < 100)
	{
		ob = new("/clone/armor/shuijing-guan");
		if (! objectp(ob))return "������Ʒ��������ϵ��ʦ��";
		
	        set("who_get/id", query("id", me), ob);
		set("who_get/time", time() + 30, ob); // 30���ڶ����ܼ�ȡ
		ob->move(me, 1);
		set("kaifu_huodong/gift_jingyan", 1, me);
		me->save();

		log_file("gift_jingyan", query("id", me) + " at " + ctime(time()) + "��ȡ��Ϊ����������:" +
		         sprintf("%d", DB_D->query_data("kaifu_huodong/gift_jingyan/count")+1) + "\n");

		DB_D->set_data("kaifu_huodong/gift_jingyan/count", DB_D->query_data("kaifu_huodong/gift_jingyan/count") + 1);
		
		
		return me->name() + NOR "�ɹ���ȡ������";
	}
	else
	{
		return "�Բ���ǰ100���콱���������ˣ�";
	}
	
	return "ף����Ϸ��죡";

}

string gift_neigong()
{
	object me, ob1,ob2;
	
	if (! objectp(me = this_player()))return "";
	
	if (query("kaifu_huodong/gift_neigong", me))
		return me->name() + NOR "���Ѿ���ȡ���ý����ˣ�";	
	
	if (me->query_skill("force", 1) < 500)
	{
		return me->name() +  NOR "������ڹ�����500�������ܲ���û��\n";
	}
	
	// ֻ����ǰ100�������ȡ
	if (DB_D->query_data("kaifu_huodong/gift_neigong/count") < 100)
	{
		ob1 = new("/clone/fam/item/wuming-tongren");
		if (! objectp(ob1))return "������Ʒ��������ϵ��ʦ��";
		ob2 = new("/clone/fam/item/wuming-tongren");
		if (! objectp(ob2))return "������Ʒ��������ϵ��ʦ��";
				
	        set("who_get/id", query("id", me), ob1);
		set("who_get/time", time() + 30, ob1); // 30���ڶ����ܼ�ȡ
		ob1->move(me, 1);
	        set("who_get/id", query("id", me), ob2);
		set("who_get/time", time() + 30, ob2); // 30���ڶ����ܼ�ȡ
		ob2->move(me, 1);
		set("kaifu_huodong/gift_neigong", 1, me);		
		me->save();

		log_file("gift_neigong", query("id", me) + " at " + ctime(time()) + "��ȡ�ڹ�����������:" +
		         sprintf("%d", DB_D->query_data("kaifu_huodong/gift_neigong/count")+1) + "\n");

		DB_D->set_data("kaifu_huodong/gift_neigong/count", DB_D->query_data("kaifu_huodong/gift_neigong/count") + 1);
		return me->name() + NOR "�ɹ���ȡ������";	
	}
	else
	{
		return "�Բ���ǰ100���콱���������ˣ�";
	}
	
	return "ף����Ϸ��죡";
}

string gift_ultra()
{
	object me,ob1,ob2;
	
	if (! objectp(me = this_player()))return "";

	if (query("kaifu_huodong/gift_ultra", me))
		return me->name() + NOR "���Ѿ���ȡ���ý����ˣ�";
		
	if (! ultrap(me))
	{
		return me->name() +  NOR "�㻹û�л����ʦ�ƺţ����ܲ���û��\n";
	}
	
	// ֻ����ǰ100�������ȡ
	if (DB_D->query_data("kaifu_huodong/gift_rendu/count") < 100)
	{
		ob1 = new("/clone/tongren/tongren1");
		if (! objectp(ob1))return "������Ʒ��������ϵ��ʦ��";
		ob2 = new("/clone/tongren/tongren2");
		if (! objectp(ob2))return "������Ʒ��������ϵ��ʦ��";

	        set("who_get/id", query("id", me), ob1);
		set("who_get/time", time() + 30, ob1); // 30���ڶ����ܼ�ȡ
		ob1->move(me, 1);
	        set("who_get/id", query("id", me), ob2);
		set("who_get/time", time() + 30, ob2); // 30���ڶ����ܼ�ȡ
		ob2->move(me, 1);
		set("kaifu_huodong/gift_ultra", 1, me);		
		me->save();

		log_file("gift_ultra", query("id", me) + " at " + ctime(time()) + "��ȡ��ʦ����������:" +
		         sprintf("%d", DB_D->query_data("kaifu_huodong/gift_rendu/count")+1) + "\n");

		DB_D->set_data("kaifu_huodong/gift_rendu/count", DB_D->query_data("kaifu_huodong/gift_rendu/count") + 1);
		return me->name() + NOR "�ɹ���ȡ������";	
	}
	else
	{
		return "�Բ���ǰ100���콱���������ˣ�";
	}
	
	return "ף����Ϸ��죡";

}

string gift_pthuiyuan()
{
	object me, ob;
	

	if (! objectp(me = this_player()))return "";
	
	if (query("kaifu_huodong/gift_pthuiyuan", me))
		return me->name() + NOR "���Ѿ���ȡ���ý����ˣ�";
			
	if (! MEMBER_D->is_valid_member(query("id",me)))
	{
		return me->name() +  NOR "�㲻����Ч��Ա�����ܲ���û��\n";
	}
	
	// ֻ����ǰ100�������ȡ
	if (DB_D->query_data("kaifu_huodong/gift_pthuiyuan/count") < 100)
	{
		ob = new("/clone/armor/yecha2");
		if (! objectp(ob))return "������Ʒ��������ϵ��ʦ��";
		
	        set("who_get/id", query("id", me), ob);
		set("who_get/time", time() + 30, ob); // 30���ڶ����ܼ�ȡ
		ob->move(me, 1);
		set("kaifu_huodong/gift_pthuiyuan", 1, me);
		me->save();

		log_file("gift_pthuiyuan", me->query("id") + " at " + ctime(time()) + "��ȡ��Ϊ����������:" +
		         sprintf("%d", DB_D->query_data("kaifu_huodong/gift_pthuiyuan/count")+1) + "\n");

		DB_D->set_data("kaifu_huodong/gift_pthuiyuan/count", DB_D->query_data("kaifu_huodong/gift_pthuiyuan/count") + 1);
		
		return me->name() + NOR "�ɹ���ȡ������";
	}
	else
	{
		return "�Բ���ǰ100���콱���������ˣ�";
	}
	
	return "ף����Ϸ��죡";
}

string gift_zshuiyuan()
{
	object me, ob1, ob2, ob3, ob4, ob5, ob6, ob7;

	if (! objectp(me = this_player()))return "";

	if (query("kaifu_huodong/gift_zshuiyuan", me))
		return me->name() + NOR "���Ѿ���ȡ���ý����ˣ�";

	if (MEMBER_D->db_query_member(me, "endtime") < 1888888888)
	{
		return me->name() +  NOR "�㲻�������Ա�����ܲ���û��\n";
	}

	// ֻ����ǰ20�������ȡ
	if (DB_D->query_data("kaifu_huodong/gift_zshuiyuan/count") < 20)
	{
		ob1 = new("/clone/goods/wisdom_armor");
		if (! objectp(ob1))return "������Ʒ1��������ϵ��ʦ��";
		ob2 = new("/clone/goods/wisdom_cloth");
		if (! objectp(ob2))return "������Ʒ2��������ϵ��ʦ��";
		ob3 = new("/clone/goods/wisdom_head");
		if (! objectp(ob3))return "������Ʒ3��������ϵ��ʦ��";
		ob4 = new("/clone/goods/wisdom_boots");
		if (! objectp(ob4))return "������Ʒ4��������ϵ��ʦ��";	
		ob5 = new("/clone/goods/wisdom_wrists");
		if (! objectp(ob5))return "������Ʒ5��������ϵ��ʦ��";
		ob6 = new("/clone/goods/wisdom_waist");
		if (! objectp(ob6))return "������Ʒ6��������ϵ��ʦ��";	
		ob7 = new("/clone/goods/wisdom_surcoat");
		if (! objectp(ob7))return "������Ʒ7��������ϵ��ʦ��";	
									
	        set("who_get/id", query("id", me), ob1);
		set("who_get/time", time() + 30, ob1); // 30���ڶ����ܼ�ȡ
		ob1->move(me, 1);
	        set("who_get/id", query("id", me), ob2);
		set("who_get/time", time() + 30, ob2); // 30���ڶ����ܼ�ȡ
		ob2->move(me, 1);
	        set("who_get/id", query("id", me), ob3);
		set("who_get/time", time() + 30, ob3); // 30���ڶ����ܼ�ȡ
		ob3->move(me, 1);
	        set("who_get/id", query("id", me), ob4);
		set("who_get/time", time() + 30, ob4); // 30���ڶ����ܼ�ȡ
		ob4->move(me, 1);
	        set("who_get/id", query("id", me), ob5);
		set("who_get/time", time() + 30, ob5); // 30���ڶ����ܼ�ȡ
		ob5->move(me, 1);
	        set("who_get/id", query("id", me), ob6);
		set("who_get/time", time() + 30, ob6); // 30���ڶ����ܼ�ȡ
		ob6->move(me, 1);
	        set("who_get/id", query("id", me), ob7);
		set("who_get/time", time() + 30, ob7); // 30���ڶ����ܼ�ȡ
		ob7->move(me, 1);
														
		set("kaifu_huodong/gift_zshuiyuan", 1, me);
		me->save();

		log_file("gift_zshuiyuan", query("id", me) + " at " + ctime(time()) + "��ȡ�����Ա����������:" +
		         sprintf("%d", DB_D->query_data("kaifu_huodong/gift_zshuiyuan/count")+1) + "\n");

		DB_D->set_data("kaifu_huodong/gift_zshuiyuan/count", DB_D->query_data("kaifu_huodong/gift_zshuiyuan/count") + 1);

		
		return me->name() + NOR "�ɹ���ȡ������";
	}
	else
	{
		return "�Բ���ǰ20���콱���������ˣ�";
	}

	return "ף����Ϸ��죡";

}
