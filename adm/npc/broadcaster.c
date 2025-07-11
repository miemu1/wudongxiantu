#include <ansi.h>
inherit NPC;

void receive_message(string msgclass, string msg);

void create()
{
        set_name(HIY "金庸" NOR, ({ "jin yong", "jin", "yong" }) );
        set("title", HIG"武侠始祖" NOR);
        set("nickname", HIC"一支玉笔尽舒怀"NOR);
        set("gender", "男性");
        set("age", 35);
        set("no_get", 1);
        set("long",
           "这就是武侠世界的创始人金庸金大侠。\n");
        set("env/immortal",1);
        set("env/invisible",1);
        set_heart_beat(1);
        setup();
}

void heart_beat()
{
        int status;
        object enemy,npc;
        status = BIWU_D->get_status();
        if (status != 2) return;

        enemy = BIWU_D->get_enemy();
        npc = BIWU_D->get_npc();
        if (!objectp(enemy) ||
            !living(enemy)||
            base_name(environment(enemy)) != "/d/city/biwu_leitai" ||
            !interactive(enemy))
        {
                if (objectp(enemy) && base_name(environment(enemy)) == "/d/city/biwu_dating")
                {
                        message_vision(HIC"几个大汉冲上擂台，手忙脚乱的把$N抬走了。\n"NOR,enemy);
                        enemy->move("/d/city/biwu_restroom");
                        message_vision(HIC"几个大汉手忙脚乱的把$N抬了进来。\n"NOR,enemy);
                }
                if (objectp(npc))
                {
                        message_vision(HIW"$N冷哼一声，弹一下衣服上的尘土，转身走进内台。。\n"NOR,npc);
                        destruct(npc);
                }
                BIWU_D->finish_biwu();
        }
        return;
}
