// Room: /tangmen/bdajie1.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",
"һ����ֱ�Ĵ���ʯ�ֵ������ߵĵ��̿��Ǻõط������߲�ʱ�ش���С\n"
"��ߺ���������ˡ����ˡ��������ˡ������̲�ס���ȥ����������ֻ��ͣ\n"
"�Ĵ�����˻���������Ǳ߻���ʲô�������ˣ�������վ�ˣ���ȥ�ܶ�ĵ�\n"
"������\n"
);
        set("outdoors", "����");
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"kedian",
                "south" : __DIR__"zhongxin",
                "west"  : __DIR__"tmyizhan",
                "north" : __DIR__"bdajie2",
        ]));

        setup();
        replace_program(ROOM);
}

