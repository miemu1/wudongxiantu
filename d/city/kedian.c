// Room: /city/kedian.c

#include <room.h>
#include <localtime.h>

inherit CREATE_CHAT_ROOM;
int fly(string arg);
string do_fly();
void create()
{
	set("short", "������ջ");
	set("long", @LONG
������������¡�ı�����ջ������������οͶ�ѡ���ڴ���š�һ������
�ĵ�С����������æ������ת���Ӵ�����ǻ�����Ŀ��ˡ��͵�����˴Ӳ�¶�棬��������˭�������������Ÿ��ָ����Ĳ²⡣
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("item_desc", ([
		"�����ӡ�" : "¥���ŷ���ÿҹ10����������������϶�¥��Ϣ������Ҫ����С��10�����ӡ�\n"
		ZJOBACTS2+ZJMENUF(2,3,9,28)"��Ǯס��:give 10 silver to xiao er\n",
		"�����桿" :HIW"��ӭ�����䶯��;��
      
��������ؼ�Ⱥ

                                                  
												 
�䶯��;��"NOR"\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		"/adm/npc/shizhe" : 1,
		//"/adm/npc/fuben" : 1,
		 "/adm/npc/duihuan"    : 1,
		 "/d/city/npc/jijin"    : 1,
	]));
	set("action_list", ([
		HIY"���ְ�ʦ"NOR:"do_fly",
		"���浵��":"save",

	]));
	set("exits", ([
		"west" : __DIR__"beidajie1",
		"up"   : __DIR__"kedian2",
		"north": __DIR__"liaotian",
		"east" : __DIR__"tingyvge2",
		"south" : __DIR__"tianji",

	]));
set("zhong",1);	
	setup();
}

mapping shuzi=([
		"zige dan": 3,						
	]);


void init()
{
	add_all_action();
    add_action("fly","fly2");
    add_action("do_fly","do_fly");    
}

string do_fly()
{
	write(ZJOBLONG"�Ƽ�����������ĸ����ɣ�\n"
		ZJOBACTS2+ZJMENUF(1,1,8,30)+
		"��ɽ��(�����Ƽ�-������):fly2 huashan"ZJSEP
		"��ң��(�����Ƽ�-������):fly2 xiaoyao"ZJSEP
		"Ѫ����(�����Ƽ�-������):fly2 xuedao"ZJSEP
		"���ѹ�(�����Ƽ�-������):fly2 lingjiu\n");
		return "������";
}
int fly(string arg)
{
	object me=this_player();
	if (arg=="huashan") me->move("/d/huashan/qunxianguan");
	else if (arg=="xiaoyao") me->move("/d/xiaoyao/muwu3");
	else if (arg=="xuedao") me->move("/d/xuedao/wangyougu");
	else if (arg=="lingjiu") me->move("/d/lingjiu/damen");
	else write(HIR"\n�������"NOR"\n");
	return 1;
}


int valid_leave(object me, string dir)
{

	if (! me->query_temp("rent_paid") && dir == "up")
		return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if (me->query_temp("rent_paid") && dir == "west")
		return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ����˻���ΪС���ź����أ�\n");
//	if (me->query("id")!="dudu66" && dir == "east")
//		return notify_fail(HIY"��û���ʸ���룡\n"NOR);
 
	return ::valid_leave(me, dir);
}

