// zxzt.c 紫霄震天丸

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "紫霄震天丸" NOR, ({ "zhentian wan", "zhentian", "wan" }) );
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "道祖熔炼九九八十一万年才成丹功效甚重。\n" NOR);
                set("value", 0);
                set("unit", "颗");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        string mapsk;
        int effect;
        int neili;

        log_file("static/using", sprintf("%s(%s) eat 紫霄震天丸 at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;

        // if (me->query("skybook/item/zhenyu"))
        if (! VERSION_D->is_release_server())
        {
	        message_vision(HIR "$N" HIR "一仰脖，吞下了一颗紫霄震天丸，却听$P"
                               HIR "一声尖哮，喷出一口鲜血，仰面便倒。\n" NOR, me);

                me->set_temp("die_reason", "贪吃镇狱惊天丸，结果弄得全身筋脉尽断"
                                           "而亡");
                me->die(); 
        } else
	{
        	message_vision(HIW "$N" HIW "一仰脖，吞下了一颗紫霄震天丸，只见$P"
                               HIW "全身着了火一样，难受的不行。\n" NOR, me);

        	me->add("combat_exp", 0 + random(0));
        	me->add("magic_points", 0);
        	me->add("potential", 0);

               	me->set_skill("force", 180);
               	me->set_skill("beiming-shengong", 180);
               	me->set_skill("dodge", 180);
               	me->set_skill("unarmed", 180);
               	me->set_skill("parry", 180);
               	me->set_skill("sword", 180);
               	me->set_skill("blade", 180);

        	me->improve_neili(0);
        	me->improve_jingli(0);
                me->add("skybook/item/zxzt", 1);
	}
        destruct(this_object());
        return 1;
}

int query_autoload()
{
        return 1;
}
