#include <weapon.h>
#include <ansi.h>
#include <armor.h> 
inherit SWORD;

void create()
{
        set_name(NOR + HIC "����" HIY "��ħ��" NOR, ({ "tianlong jian", "jian" }));
        set_weight(1200);
                set("unit", "��");
                set("long", "����һ�������������ϸ������ɽ��ϼ�����У�������������\n");
                set("value", 5000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        set("weapon_prop/fatal_blow", 35);
        set("weapon_prop/add_forget", 7);
        set("weapon_prop/avoid_parry", 5);
        set("weapon_prop/avoid_dodge", 5);
        set("weapon_prop/avoid_force", 5);
        set("weapon_prop/avoid_attack", 5);
        init_sword(2500);
        setup();
}



