//menwei.c		�Ĵ����š��

inherit ROOM;

void create()
{
	set("short", "�");
	set("long",
"��������źС���Ĳ��ƽ�����ŵ������Ƕ�ϲ����������Ƚϸ���\n"
"���˵��书�ߵͣ������ɲ�ҪС����Щ���ˣ�����Ҳ�������֡���������\n"
"��ͤ�ˮ��\n"
);
	set("exits", ([	"east" : __DIR__"shuige1",]));
	set("objects", ([__DIR__"npc/menwei" : 2,]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
