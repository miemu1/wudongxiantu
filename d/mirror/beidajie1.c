// Room: /city/beidajie1.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
	������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң������
�����ϱ���ȥ��������һ�����ֵĹ㳡��������һ��������¡�Ŀ�ջ�����Ը���
�����ǽ�����������˵Ҳ�������ǵ��Ļ�ص㡣������һ��Ǯׯ��������������
�����Ľ���������
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west" : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
	]));

	setup();
}
//�Ǿ���
int is_mirror() { return 1; }