inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "�������");
        set("long", @LONG
������ͨ�����ξ��ǵ����������������ս��ֹ���Եø����
��������ʱ����������ƥ�ɱ�����������һ�����̣���;��ʱ������
������֣���������ͣ���ĺá�
LONG );
        set("outdoors", "xiangyang");
        set("no_fly",1);

        set("exits", ([
                "east"  : "/d/xiangyang/westgate2", 
                "west"  : __DIR__"yidao2",
        ]));
        setup();
}
