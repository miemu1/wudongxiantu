// Room: /tangmen/edajie.c
 

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",
"����һ����������ʯ��ֵ���������һ�����ӣ�������ϰ������ŵ�\n"
"���ˣ���һЩ������ϱ���һ�����ţ���˵���������ϵ�Ǯׯ�ˣ�����\n"
"������һ�㰡���ܶ���ԭ�������˶���Ǯ���������\n"
);
        set("outdoors", "����");
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"zhongxin",
                "south" : __DIR__"tsqianz",
                "north" : __DIR__"tjpuzi",
        ]));

        setup();
        replace_program(ROOM);
}

