#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "�����ǻ�ɽ�۽��ı��侺������");
	set("exits", ([
		"out" : __DIR__"enter",
	]));
	set("objects",([
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	me->force_me("quit");
	return 0;
}
void init()
{
   add_action("do_eat", "eat");
   add_action("do_eat", "use");


}
int do_eat(string arg){

   object me = this_player();

 tell_object(me,"�۽�����ʹ���κ�ҩ���\n");
 return 1;

}