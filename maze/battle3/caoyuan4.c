inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "���ԭ");
        set("long", @LONG
��������ɹŴ��ԭ�ˣ��ɹž�Ӫ���ڲ�Զ���ˣ����ƺ�������
���ɹž��ӵ����������㲻�������˽Ų����������δ�������٣���
ͼ͵͵�ӽ��ɹž��ľ�Ӫ��
LONG );
        set("outdoors", "xiangyang");
        set("no_magic",1);

        set("exits", ([
                   "south"  : __DIR__"caoyuan3",
                   "north"  : __DIR__"myuanmen1",
        ]));

        setup();
} 
