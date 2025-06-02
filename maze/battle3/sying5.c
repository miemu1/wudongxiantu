#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_attack(string arg);

void create()
{
        set("short", "��ǽ��");
        set("long", @LONG
������ǡ����Ρ���Ӫǰ��ǽ��
LONG );

        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */
               "down" :   __DIR__"syuanmen1",
        ]));

        create_door("down", "����", "up", DOOR_CLOSED);
        setup();
}

void init()
{
        if (interactive(this_player()))
        add_action("do_attack", ({ "throw", "touzhi", "luoshi" }));
}
 
int do_attack(string arg)
{
        object me, ob, room, env;
        string dir, who;
        string zhen, craft;
        mapping exits;

        me = this_player();
        env = environment(me);

        if (! arg) return notify_fail("��Ҫָ�Ӳ��ӳ�˭���������\n");

        /*
        if( query("env/auto_war", me) )
                return notify_fail("���Ѿ�����Ϊ��ϵͳ�Զ�ָ����ս�������Լ����������޸����á�\n");
*/
        
        if( query_temp("warquest/attack", me) )
                return notify_fail("��Ķ������������������Ҫ�ҷ������ˣ�\n");

        if( !query("craft/siegecity/luoshi", me) )
                return notify_fail("��Ŀǰ��û��ͨ�����س�ϵ�������С���ʯ�����ֱ�����\n");
                
        if( !query_temp("warquest/train", me) )
                return notify_fail("��δ��һ��һ�䣬ָ�Ӹ�ʲôѽ��\n");

        if( query_temp("warquest/train", me) != "infantry" )
                return notify_fail("���ֲ������첽�������ʵʩ��ʯ��\n");
        
        if( query_temp("warquest/group", me)<1 )
                return notify_fail("��Ķ����Ѿ���ʧ�������޷��������ˣ�\n");

        if (WAR_D->query_stones(me) < 1)
                return notify_fail("��ľ�Ӫ���Ѿ�û���κ���ľ��ʯ���޷�ʵʩ��ʯ�ˣ�\n");
                                
        if (sscanf(arg, "%s on %s", who, dir) != 2)
                return notify_fail("ָ���ʽ�������� luoshi <����> on <����> ָ����Ķ��飡\n");

        if( !mapp(exits=query("exits", env)) || undefinedp(exits[dir]) )
                return notify_fail("�޷��ҵ�Ŀ�꣬���� luoshi <����> on <����> ָ����Ķ��飡\n");

        room = get_object(exits[dir]);
        if (! room) return notify_fail("�޷��ҵ�Ŀ�꣬���� luoshi <����> on <����> ָ����Ķ��飡\n");

        if( query("no_fight", room) )
                return notify_fail("���ﲻ����˺ɱ����\n");

        if (! objectp(ob = present(who, room)))
                    return notify_fail("�޷��ҵ�Ŀ�꣬���� luoshi <����> on <����> ָ����Ķ��飡\n");

        if( !query_temp("warquest", ob) || query_temp("warquest/party", ob) != "meng" )
                    return notify_fail("������������ǲ�Ҫ���������Ƿǵĺã�\n");

        message_vision(HIY "$N�����б���һ�ӣ���ȵ�������Ӫ׼����о���ʯ����\n" NOR, me, ob);
        
        zhen = "��ͨ��";
        craft = "��ʯ";
         set_temp("warquest/attack", 1, me);
        me->start_call_out((: call_other, WAR_D, "attack_over", me :), 10);
        WAR_D->do_attack(me, ob, zhen, craft, env, dir, room);
        return 1;
}
