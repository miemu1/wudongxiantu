// Room: /city/guangchang.c
// YZC 1995/12/04 
inherit ROOM;

string look_notice();

void create()
{
    set("short", "����㳡");
    set("long", @LONG
    �����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������ʯ���档һЩ���ֺ���
���������������������������������ݡ�������һ�ô��������̸���ڣ���
������ǧ������䣬���������е���ʷ��֤�����ɵײ���һ���ܴ�Ķ�(shudong)��
����Կ������������Ը��ص��������������������������У�һ�ɷ������󣬶���
��ʱ�ش������ʵĶ�������������������������ˣ�һƬ�ྲ�������Ϲ�һ�����

                        ��[1;33m�Σϣԣɣã�[2;37;0m

LONG
    );
        set("outdoors", "city");
    set("item_desc", ([
        "shudong" : "����һ���ڲ����еĴ󶴣����治֪����Щʲô�Ź֡�\n",
        "����"  :   "һ��֦Ҷïʢ�Ĵ������������ƺ�������(climb)��ȥ��\n",
        "������":   "һ��֦Ҷïʢ�Ĵ������������ƺ�������(climb)��ȥ��\n",
        "��"    :   "һ��֦Ҷïʢ�Ĵ������������ƺ�������(climb)��ȥ��\n",
        "tree"  :   "һ��֦Ҷïʢ�Ĵ������������ƺ�������(climb)��ȥ��\n",
    ]));
    set("exits", ([
        "east" : __DIR__"dongdajie1",
        "south" : __DIR__"nandajie1",
        "west" : __DIR__"xidajie1",
        "north" : __DIR__"beidajie1",
	"down" : __DIR__"drop",
    ]));
    setup();
}

void init()
{
        add_action("do_climb", "climb");
}
  
int do_climb(string arg)
{
    object me;
    mixed *local;
    local=localtime(time());
    me=this_player();
        if( !arg || arg!="up") return notify_fail("��Ҫ���ĸ���������\n");

    if (me->query("gender")!="Ů��")
    message("vision",
        me->name() + "սս���������Ŵ��������̸���ƨ��һŤһŤ����������\n",
        environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "����һ������ȹƮƮ�������Ӱ���ϴ�������\n",
        environment(me), ({me}) );
    else message("vision",
        me->name() + "սս������ץס����������ȥ��\n", environment(me), ({me}) );
                me->move(__DIR__"chatroom");
    if (me->query("gender")!="Ů��")
        message("vision",
        me->name() + "�������������������\n",
                environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision","һ������������㶨��һ����"+
        me->name() + "�Ѿ���������������ǰ��\n",
        environment(me), ({me}) );
    else  message("vision", me->name() + "սս�����ش���������������\n", environment(me), ({me}) );   
    return 1;
}
//�Ǿ���
int is_mirror() { return 1; }
