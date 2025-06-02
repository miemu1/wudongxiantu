// Room: /city/beidajie1.c

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң������
�����ϱ���ȥ��������һ�����ֵĹ㳡��������һ��������¡�Ŀ�ջ��������һ��Ǯׯ��
LONG
	);
	set("outdoors", "city");
	set("objects", ([
		CLASS_D("ouyang") + "/ouyangke" : 1,
		"/adm/npc/zongshi":1,
		"/d/mirror/npc/office": 1,
		"/d/jjfb1/jnpc/npc2": 1,
		"/d/boss/jiangshi": 3,

		__DIR__"npc/tiaoz" : 1,	
	]));
	set("exits", ([
		"east"  : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west"  : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
		//"up" : __DIR__"liangtian",
	]));

	setup();
}
