inherit ROOM;
#include <ansi.h> 
void create ()
{
  set ("short", "����");
  set ("long", HIG@LONG
����һƬ���ʣ�ʲô�������塣���������з·�������޾���
ɱ������Ȼ����ֻ��ֵ�Ұ�޴����������˳�����צ��ֵ�������
����������ֲ�������ʱ�����˰�Χ�С�
LONG);

  set("exits", ([
         "west"    : __DIR__"outlet1",
         "south"    : __DIR__"entrance",
      ]));
  set("objects", ([
         "/quest/tulong/npc/beast" : 3,
      ]));
  set("no_magic", 1);
	setup();
}

int valid_leave (object me, string dir)
{
  object beast = present("beast", this_object());

  if (dir == "west" &&  beast &&
      ! beast->is_busy() )
    return notify_fail("�����޵�סȥ·������������\n");
  return ::valid_leave(me,dir);
}

