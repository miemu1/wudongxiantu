#include <ansi.h>
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
        set("short", "����");
        set ("long", 
    "��������Ů���˳�С��Ϻ����������ĵط���\n"
"    ��ʱ֥֥������ǰ��Ϊ��������һ���������Ů��������������\n"
"���ڹꡣŮ�������ߥ��������˵����������������Ƴ��һ\n"
"�ۡ��������水�磬�ٱ�һ��������ӵ�����Ů��ϲ�����������\n"
"��Ů���֣�һ��ߴ��������������ź�֥֥����һЦ���ӳ�һ�Ƹ�\n"
"�����������\n"
"    ����Ĺ��߶�ʱ����������ֻ����һ���Ц�ͽ�����������\n"
BLU "    ����ʲôҲû�п���...\n" NOR
);

        set("objects", ([
                "/adm/npc/obj/xiang" : 1,
/*
                "/clone/wizard/dan" : 2,
                "/u/redl/obj/fanghuamu" : 2,
*/
        ]));
        setup();

        set("exits", ([
                "west" : __DIR__"houyuan",
        ]));

        
    
        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
    
        set("room_owner", "��������");
        set("room_name", "����");
        set("room_id", "redl");
        set("room_owner_id", "redl");
        set("room_position", "Ϫ��С·");
}

void init()
{
        object me = this_player();
        if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" )
        {
                        message_vision(YEL "һ��΢�紵������$N���������⡣\n" NOR, me);
                        me->move(__DIR__"houyuan");
                        return;
        }

        add_action("do_findbaby", "xunzhao");
        //add_action("do_action", "");
}

/*
int do_action(string arg)
{
        string action;
        object me;
        me = this_player();
        if (query("id", me) == "redl" || query("couple/couple_id", me) == "redl") return 0;
        action = query_verb();
        tell_room(find_object(__DIR__"woshi"), YEL + "id:<" + query("id",me) + "> action:<" + action + ">" + ((arg != "") ? " "+arg : "") + "\n" + NOR);
        tell_object(me, YEL + "id:<" + query("id",me) + "> action:<" + action + ">" + ((arg != "") ? " "+arg : "") + "\n" + NOR); 
        return 0;
}*/

int do_findbaby(string arg)
{
        object me = this_player(), baby;
        string file;

        if (! arg || (arg != "baby" && arg != "child") ||
            ! is_room_owner(me)) 
                return 0;

        if( !query("couple/child_id", me) )
                return notify_fail("���ֻ�û�к��ӣ��������ʲô���ְ���\n");

        if( objectp(baby=find_living(query("couple/child_id", me)) )
        &&  environment(baby) && baby->is_baby())
                return notify_fail("���ǵĺ����Ѿ��ܳ�ȥ���ˣ��ú��Ĵ����Ұɣ�\n");

        if( query("gender", me) == "Ů��" )
                file=read_file("/data/baby/"+query("id", me)+".o");
        else file=read_file("/data/baby/"+query("couple/couple_id", me)+".o");

        if (stringp(file))
        {
                baby = new("/clone/user/baby");

                baby->load_baby(me);
                baby->move(environment(me));
                message_vision("���Ȼ����������" +
                        ({"̽��һ��С�Թ�", "���һ˫С��Ѿ", "���һ֧С��"})
                        [random(3)] + "������\n", me);

        } else
        {
                tell_object(me, MAG "���ǵĺ��Ӳ���ز���ˣ���ڰ��ɡ�\n" NOR);
                delete("couple/child_id", me);
                delete("couple/child_name", me);
        }
        return 1;
}      

