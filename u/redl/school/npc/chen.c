// This program is a part of NITAN MudLIB 
// redl 2013/8

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(NOR "ꐷ�" NOR, ({ "chen fei", "chen" }));
                set("nickname", CYN "���Ŵ���" NOR);
        set("long", @LONG
����һ����ѧУ�￴�ŵĴ��壬����ְ�أ������޹���
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
                "��ѧ" : "����һ�����ŵĸ���㵽������ֱ�Ӹ�Ǯ����ʦ���С�\n"+NOR,
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}




