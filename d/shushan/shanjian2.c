//����ɽ�ɡ�mhxy-yushu 2001/2
#include <ansi.h>
inherit ROOM;
int do_dive();
void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

������һ��С��ˮ̶�����������ϵ��ٲ���������ˮ�������µ�����
��ȥ��������ˮ̶�ɣ�������Ŀ��˿����ܣ�ȫ���������ͱڣ���
�����ȥ�������ˣ�ֻ�������漣������
LONG);

  set("exits", ([      
         "south" : __DIR__"shanjian",
 ]));
 setup();
}
void init()
{
    add_action("do_dive", "dive");
    add_action("do_dive", "qian");		
}
int do_dive()
{   
   object me, zhou;
   object ridee;
   me=this_player();
  me->move(__DIR__"midao");
  message_vision(HIW"$N����ˮ���ĳ����֪������������һ���ط���\n"NOR,me);
  message_vision(HIR"$N��ͷͻȻһ������,��ʱʧȥ��֪����\n"NOR,me);
  me->unconcious();
  return 1;
}

