inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "ɽ´");
        set("long", @LONG
���������������ɽ´��Ҳ�������ɹž��ӵıؾ�֮·����·��
��������ʮ�����ߣ����Ƕ��ڳ����Ĵ����˵�����������ߵ�·����
���Ѿ����˼�ƽ�������ˡ�
LONG );
        set("outdoors", "xiangyang");
        set("no_magic",1);

        set("exits", ([
               "south"  : __DIR__"conglin3",
               "north"  : __DIR__"conglin1", 
        ]));

        setup();
} 
