// This program is a part of NT MudLIB 
 
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
 
void create()
{
        set_name(HIY "��" HIW "֮" HIM "ף��" NOR HIC "����" NOR, ({ "zhufu staff", "staff", "zhang" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY "�������֮ף�����ȡ�\n" NOR);
                set("value", 3000); 
                set("no_sell", "����������������\n");
                set("rigidity",8000);   
                set("material", "tian jing");
                set("no_pawn", 1);
        }
        
        set("quality_level", 2); 
        init_staff(500);
        setup();
}



