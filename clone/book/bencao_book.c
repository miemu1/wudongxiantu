// advance_unarmed.c

inherit ITEM;

void create()
{
        set_name("「本草纲目」", ({ "bencao gangmu", "book" }));
        set_weight(600);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"封面上写著「本草纲目」，是一个医学的百科全书。\n");
                set("value", 2000);
				set("no_drop", "这样东西不能离开你。\n");
				set("no_put",1);
				set("no_sell",1);
				set("no_save",1);
				set("no_give",1);
				set("nopaimai",1);
                set("material", "paper");
                set("skill", ([
                        "name":         "medical",
                        "exp_required": 1000,
                        "jing_cost":    30,
                        "difficulty":   25,
                        "max_skill":    500,
                ]));
        }
}

