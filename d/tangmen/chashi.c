//chashi.c		�Ĵ����š�����

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",
"��������źС���Ĳ��ҡ�ͨ�����ŵ��Ӷ�ϲ��������̸��˵�أ�����\n"
"���Ե��书��չ��Ҳʱ��̸��һЩ�����ж���ԹԹ��������������ͤ�ˮ��\n"
);
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ��ʮ��������\n",
	]));
	set("exits", ([	
			"west" : __DIR__"shuige1",
	]));
	set("area", "����ͤ�ˮ��");
	setup();
      //  "/clone/board/tangmen_b"->foo(); 
	replace_program(ROOM);
}
