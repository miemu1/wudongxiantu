// Room: chufang.c

inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
���ǳ�����������ˮ��ǰ���в��ٵĻ����ժ�˺�
��ϴ���������һЩ���վ������ֱð���͹���ǰŬ���ķ����Ÿ�ɫ
���ȣ���һ�����ִ�ŵ�����������ߺ�ȣ�ָ�ֻ��ŵ�ȴ���ɻ
LONG );
	set("exits", ([
		"down" : __DIR__"chufang",
        "up" : __DIR__"work3",		
	]));
	set("objects", ([
		__DIR__"npc/chushixuetu" : 1,
	]) );
	set("no_fight", 1);
	set("lx_chaocai", 1);	
	set("no_sleep_room", 1);
	setup();
}
