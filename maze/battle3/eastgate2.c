// Room: /d/xiangyang/eastgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "��������");
        set("long", @LONG
�����������ǵĶ����ţ�ֻ�������Ϸ����š������š��������֡�
���Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С����
�����Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء��������ɹ���
���ַ������ǣ�����������൱���ܣ�����һЩ�ٱ��������̲�Ҫ��
�����ǵ��ˡ�
LONG );
        set("outdoors", "xiangyang");

        set("exits", ([
                "west"  : __DIR__"eastgate1",
                "east"  : __DIR__"yidao",
        ]));
        set("objects", ([
                "/d/city/npc/bing" : 2,
        ]));
        set("coor/x", -7770);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
}
