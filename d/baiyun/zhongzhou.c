// Room: /d/fuzhou/zhongzhou.c

inherit ROOM;

void create()
{
	set("short", "�ʹ���԰");
	set("long", @LONG
����ܾ���ǰ����������Ұ������֪��ʲôʱ���𣬻�����һ�Ρ���Ҳû�п����������Ͼ��ǽ����ˣ����������ض��ļ���˭Ҳ��֪����������������ʲô��
LONG );
	set("exits", ([
		"north" : __DIR__"nanmen",
		//"south" : __DIR__"puxian",
	]));

	set("objects", ([
		"/kungfu/class/baiyun/ye" :1,
	]));
set("outdoors", "by");
	setup();
}

