#include <ansi.h>
inherit NPC;
void create()
{
        set_name("̫��", ({ "tai jian", "gonggong"}));
        set("gender", "����");
        set("age", random(20) + 20);

        set("long","����һ�����ǻʹ��е�һ��̫�࣬����Ϊ�ʵ۴����౾��\n");
        set("combat_exp", 80000);
        set("attitude", "peaceful");
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("max_neili",2000);
        set("neili",1000);

        setup();
        carry_object("clone/misc/cloth")->wear();
}            
