// advance_parry.c

inherit ITEM;

void create()
{
	set_name(MAG"��������"NOR, ({ "skill book", "book" }));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
" ����һ�����������项������ڴ���������ָ�\n "ZJURL("cmds:alias")ZJSIZE(27)MAG"�鿴�����ÿ��ָ��"NOR"\n ""\n "ZJURL("cmds:aliass")ZJSIZE(27)MAG"���ÿ��ָ��"NOR"\n ""\n "ZJURL("cmds:als")ZJSIZE(27)MAG"ִ��ѭ��ָ��"NOR"\n");
		set("gongji", 10);
		set("xy_money", 150);
		set("material", "paper");
		set("no_drop",1);
		set("no_put",1);
		set("no_sell",1);
		set("no_save",1);
		set("no_give",1);
		set("nopaimai",1);
		set("no_get",1);
	}
	setup();
}
init ()
{
	add_action("do_choose","choose");
	add_action("do_aliasss","aliasss");
	add_action("do_shezhi","shezhi");
	add_action("do_choose3","choose3");
	add_action("do_choose4","choose4");

}



int do_aliasss(object me, string arg)
{
	    object obj,ob,obj1,obj2,obj3,obj4;
	mapping alias;
        int count,mengxin,i;
        string a,b;
	string verb, replace, *vrbs;

		me = this_player();
        if (! arg) 

        return notify_fail(INPUTTXT(ZJSIZE(18)MAG BBLK"��ѡ����Ҫѭ��10�εĿ��ָ��"NOR,"alias aa"+" $txt#")+"\n");

	switch (arg) {
	  case "aa" :
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
		break;
	  case "bb" :
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));	
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));	
	  case "cc" :
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));	
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));	
	  case "dd" :
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));	
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));		
	  case "ee" :
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));	
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));	
	  case "ff" :
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));	
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));	
	  case "gg" :
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));	
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));	
	  case "hh" :
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));	
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));	
	  case "ii" :
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));	
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));	
	  case "jj" :
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));	
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));	
	  case "kk" :
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));	
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));	
	  case "ll" :
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));	
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));	
	  case "mm" :
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));	
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));	
	break;

	  default :
		message_vision(HIC "���ִ�������ϵ��ʦ��\n" NOR,me);
	}		
              sscanf(arg, "%s ", a);


        return 1;
}