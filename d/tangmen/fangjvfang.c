//fangjvfang.c		�Ĵ����š����߷�

inherit ROOM;

void create()
{
	set("short", "���߷�");
	set("long",
"�������������ŵķ��߷�������ܴ󣬿�ǽ�ڷ��ż���ľ�ܣ������\n"
"��һЩ�����þߣ�����������ֹ����ϰ���˵��Լ������������ɫ�ģ�Ī\n"
"�����������Ŷ��е�¹Ƥ���ס�\n"
);
	set("exits", ([
		"north" : __DIR__"nzlange2",
	]));
	set("objects", ([
                "/d/city/npc/obj/tiejia" : 4
        ]));

	set("no_fight", 1);
	set("area", "����");	
	setup();
	replace_program(ROOM);
}
