// by luoyun_΢Ц
// banghui.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "������������ڴˡ�����������Ծۼ�������Ӵ����Լ��İ�ᣬ���һ�𹲴�������");
	set("exits", ([
		"southeast" : __DIR__"nandajie",
	]));

	set("action_list", ([
		HIG"�������"NOR:"banghui create",
	]));
	set("no_fight","1");
	setup();
}

