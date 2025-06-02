// Room: /city/bocai.c 
#include <room.h> 
inherit CREATE_CHAT_ROOM; 
	
int is_chat_room() { return 1; } 
	
void create() 
{ 
	set("short", "�����"); 
	set("long", @LONG 
����һ��ͨ��������ĵط� 
LONG 
	); 
	set("no_fight", 1); 
	set("no_sleep_room", 1);  
	set("item_desc", ([
		"���������" : "����һ��ͨ��������ıؾ�֮· \n"
			ZJOBACTS2"��ս:wdt \n",
	]));
		set("objects", ([
		//"/adm/npc/cishu" : 1,
	    
	]));
		set("action_list", ([
		"��ȡ����" : "day_sign",
	
	]));
	set("exits", ([ 
		"west" : "/d/city/kedian", 
	])); 
	
	setup(); 
} 
void init()
{
	add_action("do_sign","day_sign");
}


int do_sign(string arg)
{
	object ob,me;
	string hol,file;
	int vlv,last,times,pot;
	mapping gifts;

	me = this_player();

	last = me->query("last_day_signn");
	times = me->query("day_sign_timess");
	if(time()/86400 == last/86400)
		return notify_fail("������Ѿ���ȡ���˴�������Ŀǰ��������ȡ��"+times+"���졣\n");

	me->set("last_day_signn",time());
	times += 1;
	me->set("day_sign_timess",times);
	me->set("wdtcs",1);
	tell_object("����ȡ��һ���������ս���ᣬ��������ϧ\n");
	tell_object(me,"\n");
	log_ufile(me,"sign","��ɹ���ȡ��һ�������������\n");
	GIFT_D->check_gift(me);
	return 1;
}