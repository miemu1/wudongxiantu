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
                "east"  : __DIR__"yidao2", 
                "north"  : __DIR__"chengmen",
        ]));

        setup();
}
