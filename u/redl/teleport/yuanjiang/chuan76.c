// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h> 
inherit __DIR__"normal.c"; 

void create()
{
        //��(ji��)����(y��)����(b��ng)����(d��ng)����(w��)����(j��)����(g��ng)����(x��n)����(r��n)����(gu��)��
        set("short", "���ֲ�");
        set("long", @LONG
���ǹ�ɽ����Ӵ�Ĵ���Ⱥ������һ�����صĴ����(out)���������
LONG );
        set("objects", ([ 
                "/clone/fam/max/zaohua" : random(6)+8,
                "/d/dongtian/obj/leaf" : random(3)+2,
                "/d/dongtian/obj/yuanjing" : random(2)+1,
                "/clone/goods/tiandilu" : 1,
                "/u/redl/teleport/npc/obj/qkfz" : random(2),
                        __DIR__"npc/liu" : (!random(50) ? 1 : 0),
        ])); 
        set("stop_run", 1);
                set("no_protect", 1);
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_fly", 1);
                set("no_sleep_room", 1); 
                set("yuan_ci_num", 35);
                
        setup();
}

int user_cant_unconcious(object me)
{
        if (!playerp(me)) {
                return 0;
        }
        me->die();
    return 1;
}

int escboat(object me)
{
        string msg;
        object usr, *usrs;
        
        if (!me || !objectp(me)) return 1;
        if (!environment(me) || environment(me)!=this_object()) return 1;
        
        tell_room(this_object(), NOR BLINK HIR "\n���׵�����֮����ס�������¡һ�����ձ���...\n\n" NOR);
        usrs = filter_array(all_inventory(this_object()), (: playerp($1) :));
        
        for( int i = 0; i<sizeof(usrs); i++) {
                if (!msg) msg = NOR + HIC + query("name", usrs[i]) + NOR;
                else msg += HIG "��" + NOR + HIC + query("name", usrs[i]) + NOR;
        }
        msg = sort_msg( HIG "��˵" + msg + HIG "��" HIY "��ɽ�" HIG "��" + query("short", this_object()) + HIG + "�ӳ����졣" + NOR );
        CHANNEL_D->channel_broadcast("chat", msg);
        destruct(this_object());
        return 1;
}

int do_esc()
{
        if (this_player()->is_fighting())
             {
                tell_object(this_player(), "����ս����û���Ӵ������ѣ�\n"); 
                return -1;
        }
    if (query("blv",get_object("/u/redl/teleport/ailao"))) {
                tell_object(this_player(), "�𴬸�ûǰ��û���Ӵ������ѣ�\n"); //��������Ŷ�����dest hereˢ��
                return -1;
    }    
    escboat(this_player());
    return 1;
}

void init()
{
        object npc;
        int maxc = random(5)+6;
        
        if (!playerp(this_player())) return;
        add_action("do_esc", "out"); 
        
                for(int i = 0; i < maxc; i++ ) {
                        npc = new(__DIR__"npc/ghost");
                        set("guarder_level", random(50) + 700, npc);
                        npc->do_copyskill();
                        npc->move(this_object());
                }
                
        call_out("escboat", 300, this_player());
        ::init();
}



