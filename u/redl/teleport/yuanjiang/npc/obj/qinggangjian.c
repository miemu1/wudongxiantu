#include <weapon.h>
#include <ansi.h>
#include <armor.h> 
inherit SWORD;

void create()
{
        set_name(NOR + HIG "���" NOR, ({ "qinggang jian", "jian" }));
        set_weight(1200);
                set("unit", "��");
                set("long", "����һ�������������ϸ������ɽ���������У����з����亮��\n");
                set("value", 5000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        set("weapon_prop/fatal_blow", 32);
        set("weapon_prop/add_forget", 5);
        set("weapon_prop/avoid_parry", 3);
        set("weapon_prop/avoid_dodge", 3);
        set("weapon_prop/avoid_force", 3);
        set("weapon_prop/avoid_attack", 3);
        init_sword(1500);
        setup();
}



