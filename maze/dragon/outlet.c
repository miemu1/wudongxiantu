inherit ROOM;
#include <ansi.h> 

void create ()
{
  set ("short", "��ľ�ֳ���");
  set ("long", HIG @LONG
ͻȻ�����ò�������г�����һ��С�����ƺ��ǳ��ڣ��
LONG);

  set("exits", ([
      ]));

  set("no_magic", 1);
	setup();
}

int valid_leave (object me, string dir)
{
  me->set("startroom","/d/city/wumiao");
  me->set_temp("lost_in_greenyard",0);
  me->set_temp("out_of_greenyard",0);
  return 1;
}

