//redl 2015
#include <ansi.h> 
#include <room.h> 
inherit ROOM;

void create()
{
        set("short", "�𴬼װ�");
        set("long", @LONG
���ǹ�ɽ��ϵļװ壬����������Ǻ�����Ĵ��ա�
LONG );
                set("exits/down"  , __FILE__);
                set("exits/wiz"  , __DIR__"chuancenter");

        set("objects", ([ 
//              "/clone/fam/max/zaohua" : (!random(90) ? 1 : 0),//����nflee��npc������
        ])); 
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_fly", 1);
                set("no_magic", 1);
                set("no_sleep_room", 1); 
                set("no_kill",1);
        set("no_fight",1);
        setup();
}

int clean_up() { return 1;}

int discmds() 
{ 
        tell_object(this_player(), "�㲻��������ë��ë�š�\n");  
        return -1;  
} 


void init()
{
                int xqkf = 2;
        object room = this_object();
        add_action("discmds", ({  
                        "steal", "cast", "conjure", "array", "fight", "hit",   
                        "home", "ansuan", "touxi", "ride", "qi", "stab", "fbattle",
                        "surrender", "array", "battle", "accept", "swear",
                        "recall", "quit", "exit", "miss", "rideto",
        }));  
        
        if (!playerp(this_player())) return;
        set_temp("jinchuan/iyca", 1, this_player());
        if (query("level", this_player()) < 100)
                xqkf++;
        if (query("level", this_player()) < 200)
                xqkf++;
        set_temp("jinchuan/iesc", xqkf, this_player());
        tell_object(this_player(), NOR"������"+chinese_number(xqkf)+"��СǬ����������ͨ���������(esc)ʹ������\n��������ֻ�У������˼����׼��ʱ�䡣\n"NOR); 
        call_out("valid_leave", 30, this_player(), "down");
        this_player()->start_busy(2);
}

int valid_leave(object me, string dir)
{
        if (!me || !objectp(me)) return 1;
        if (!environment(me) || !objectp(environment(me)) || environment(me)!=this_object()) return 1;
        if (dir=="wiz" && wiz_level(me) >= 3) {
                return ::valid_leave(me, dir);
        }
    tell_object(me, NOR"��һ�Ųȿ�...\n"NOR); 
        me->move(get_object(__DIR__"chuan" + (string)random(50)));
    tell_object(me, NOR"��������Ϲ��䣬����һ��δ֪�Ĵ����\n"NOR); 
    return 1;
}

