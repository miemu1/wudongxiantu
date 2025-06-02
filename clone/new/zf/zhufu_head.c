// This program is a part of NT MudLIB 
// Written by Lonely@nitan.org
// head.c ͷ��
 
#include <ansi.h>
#include <armor.h>
 
inherit HEAD;
 
void create()
{
        set_name(HIY "��" HIW "֮" HIM "ף��" NOR YEL "ͷ��" NOR, ({ "zhufu head", "helmet", "toukui" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "��");
                set("long", HIM "����һ�����Ƶ�ͷ�������Ա���ͷ����\n" NOR);
                set("value", 1500); 
                set("armor_prop/armor", 20);
        }
        
        set("auto_load", 1); 
        set("mod_mark", "A2011");  
        set("mod_level", "M2010");  
        set("mod_name", HIY"��"HIW"֮"HIM"ף��"NOR YEL"��װ"NOR); 

        set("enchase", ([ 
                "flute" : 1,
                "used" : 1,
                "apply_prop" : ([ /* sizeof() == 2 */
                        "armor1" : 30,
                        "int" : 1,
                ]),
        ]));

        set("insert", ([ /* sizeof() == 1 */
                "1" : ([ /* sizeof() == 3 */
                        "id" : "magic stone",
                        "name" : HIM"��ʯ"NOR,
                        "apply_prop" : ([ /* sizeof() == 2 */
                                "armor1" : 30,
                                "int" : 1,
                        ]),
                ]),
        ]));
        
        set("require", ([
                "max_level" : 40,
                "max_age"   : 30,
        ]));
        set("quality_level", 2); 
        setup();
}

