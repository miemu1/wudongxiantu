#include <ansi.h>
#include <room.h>
inherit ROOM;

string *names = ({
	"盲憎",
});

void create()
{
	set("short", "挑战");
	set("long","秘境，一些隐世强者的生存之地。");

	set("objects",([
	]));
	set("npcs",([
	]));
	set("exits", ([
		"east" : "/d/city/wumiao",
	]));
	set("action_list", ([
		"入侵秘境" : "tiaozhan",
	]));
	set("no_fight", 1);
    setup();
}
void init()
{
	add_action("tiaozhan", "tiaozhan");
}

int tiaozhan(string arg)
{
	object ling,me,slnpc,slroom;
	int i;
	string msg;

	me = this_player();

	if(!objectp(ling=present("tiaozhan ling",me))){
		tell_object(me,ZJOBLONG"你没有挑战令牌，不能进行挑战！\n");
		return 1;
	}

	if(!arg)
	{
		msg = ZJOBLONG"请选择挑战级别：\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		for(i=0;i<sizeof(names);i++)
		{
			msg += names[i]+":tiaozhan "+(i+1);
			if(i<(sizeof(names)-1)) msg += ZJSEP;
		}
		tell_object(me,msg+"\n");
		return 1;
	}

	if(atoi(arg)>sizeof(names)||atoi(arg)<1)
		return notify_fail("你想干什么？\n");

	ling->add_amount(-1);
	slroom = new(__DIR__"jiaochang2");
	slroom->set("owner",me->query("id"));
	slroom->set("sllv",atoi(arg));
	//slnpc = new(__DIR__"npc/xiayan");
//	slnpc->init_data(atoi(arg));
	//slnpc->move(slroom);
	me->move(slroom);
	slroom->set_heart_beat(1);
	return 1;
}
