//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","��ɽ���칬");
  set ("long", @LONG

��ɽ���칬����ɽ���ɿ�ɽ��ʦ�������������ĵط�,
������ɽ�������ܵط���һ����ɽ�ɵ��ӣ�û�кܺ�����
�����ǲ�֪�������,������ɽ��ʥ��ͽ�ؼ�Ϊ�ϸ�
����������һ���������Ľ����(BOX)��
LONG);

  set("exits", ([
   "west" : __DIR__"sleeproom",
   "south" : __DIR__"midao",
  ]));
  set("objects", ([ 
      CLASS_D("shushan/laozu") : 1,       
  ]));
set("item_desc", ([
"BOX" : HIY"\t\�������������϶���ʲô����,��������ò�Ҫ����Ҵ�(dakai),����������ǳ���������Ķ�����\n"NOR
]) );
  setup();
}

void init()
{
	add_action("do_dakai", "dakai");
}

int do_dakai(string arg)
{
	object me,obj,killer;
	me = this_player();
	if( !arg && arg!="box" && arg!="����")
		return notify_fail("��Ҫ��ʲô? \n");
	if ( query("havezhu") )  {
	message_vision("$N�ӽ�������ó���һ��ˮ���顣\n",this_player() );
	obj=new("/d/shushan/zhenyaota/obj/shuizhu");
	obj->move(me);
	set("havezhu", 0);
	}
	if(killer=present("master jingxu", environment(me)))
	{
       message_vision("\n���������$N�ȵ����Ҷ��ҵĶ������ҿ����ǻ�Ĳ��ͷ���!\n", me);
	 killer->kill_ob(me);
	}
	me->start_busy(15);
	return 1;
}

void reset()
{
	::reset();
	set("havezhu", 1);
}