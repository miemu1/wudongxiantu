#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ħ����¥");
	set("long",""HIR"����֮·"HIY"������Զ�⣡"NOR"");
    
	set("sllv",1);
	set("objects",([
	]));

	set("action_list", ([
	    HIY"��ʼ��ս"NOR"" : "wdt",
		//HIY"����ƺ�"NOR"" : "wdtjl",
		HIR"������ս"NOR"" : "wdtjs",
	]));
	set("cost", 1);
	setup();
}

void init()
{
       add_action("wdtjs", "wdtjs");
       add_action("wdtjs1", "wdtjs1");
	   add_action("wdt", "wdt");

}

int wdt()
{
	object me,slnpc,slroom,*slrooms;
	mixed last,now;
	mapping fam;
	int lvl,i;
	string *slnpcs;
	now = localtime(time());
	me = this_player();


	if(me->query_condition("killer")){
		tell_object(me,"�����ڱ�ͨ���������������¥��\n");
		return 1;
	}

	if (me->query("wdtcs")<1){
		tell_object(me,"��û�д����ˣ������������¥��\n");
		return 1;
	}
}

int wdtjs()
{
	write(ZJOBLONG"��ȷ��Ҫ������¥��\n"ZJOBACTS2"ȷ��:wdtjs1\n");
	return 1;
}
	
int wdtjs1()
{
	object slroom ;
	object me = this_player();
	

	slroom = this_object();

	tell_object(me,sprintf(ZJOBLONG""HIY"�������"HIR"��ħ����¥"HIY"����ս��$br#"HIC"�������˵�"HIG""+chinese_number(me->query("wudaota"))+""HIC"�㣡"NOR"\n"));
	//log_file("wudaota", sprintf("%s��%s���%d��ǧ������������Ϊֵ=%d��\n",ctime(time()),me->query("id"),me->query("wudaota"),me->query("combat_exp")));
	this_player()->move("/d/city/kedian");
	this_player()->delete("wudaota");
	this_player()->add("wdtcs",-1);
	this_player()->remove_all_killer();
	destruct(slroom);
	
	return 1;
}

void nextlv(int delay)
{
	add("sllv",1);
	call_out("nextlv2",delay);
}

int nextlv2()
{
	object slnpc;
	string *slnpcs;
	object me = this_player();
	slnpcs = ({
		"/d/fuben/wudaotai/npc/sldz",
	});
	slnpc = new(slnpcs[random(sizeof(slnpcs))]);
        if(query("sllv")<10)
		slnpc->set("name","¥"+chinese_number(query("sllv"))+"�ػ���");
	    else if(query("sllv")==10)
		slnpc->set("name",HIG"���ָ���"NOR"");
	    else if(query("sllv")<30)
		slnpc->set("name",HIC"��ʿ"+chinese_number(query("sllv"))+""NOR"");
	    else if(query("sllv")==30)
		slnpc->set("name",HIY"��������"NOR);
	    else if(query("sllv")<70)
		slnpc->set("name",HIY"������"+chinese_number(query("sllv"))+""NOR"");
	    else if(query("sllv")==70)
		slnpc->set("name",HIC"��"HIG"��"NOR"");
	slnpc->move(this_object());
	return 1;
}

int valid_leave(object me, string dir)
{
	return ::valid_leave(me, dir);
}
