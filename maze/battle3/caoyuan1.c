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
                    "west"  : __DIR__"caoyuan",
                    "east"  : __DIR__"caoyuan2", 
        ]));

        setup();
} 
