// This program is a part of NITAN MudLIB 
// redl 2013/8

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(NOR "��Ҷ" NOR, ({ "ying ye", "ying" }));
                set("nickname", CYN "������" NOR);
        set("long", @LONG
����һ����ѧУ��ɨ�صĴ��裬������������ζ���ء�
LONG);
        set("gender", "����" );
        set("age", 36);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("per", 13);
        set("combat_exp", 1333000);

        set("inquiry", ([
                "��ѧ" : "����һ��ɨ�صĸ���㵽������ֱ�Ӹ�Ǯ����ʦ���С�\n"+NOR,
                "ע��" : "�ԣ���ֹ�ҵ����Ǵ��ע�����������������������г����\n"+NOR,
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}




