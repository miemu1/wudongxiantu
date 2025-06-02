
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIY"ϴ�㿨"NOR, ({"xidian ka", "ka"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("base_unit", "��");
		set("unit", "��");
		set("base_value", 1);
		set("base_weight", 1);
		set("value", 1);
		set("channel_id","ϵͳ");
		set("no_sell",1);
		set("yuanbao",2000);
		set("no_steal",1);
		set("no_shop", 1);
		set("long","����һ"+query("base_unit") +name()+"���������·�������������Ե�"ZJBR+
							HIR"ֻ��ʹ��һ�Σ�ʹ�ú�һ���в���������ļ��ܽ�ֱ�ӱ�ɾ�������ã�"NOR"\n" );
		set("yuanbao", 1000);
	}
	set("action_list", ([
		"ʹ��" : "usesxidian",
	]));
	set_amount(1);
	setup();
}
void init()
{
	add_action("do_uses", "usesxidian");
}

varargs int do_uses(string arg)
{
	mapping shuxing=([]), my;
	string *sname, str, line;
	int i;
	int max_sx, max_sx2;
	int tmpstr, tmpint, tmpcon, tmpdex;
	object me = this_player();
		
	if (me->query("usesxidian", 1)) {
		tell_object(me, "���Ѿ�ʹ�ù�һ��ϴ�㿨�ˣ���������ʹ�á�\n");
		return 1;
	}
	if(!arg) {
		str = ZJOBLONG+ "����������·�������������"ZJBR+HIR+ZJSIZE(24)
										+"������ѡ��"NOR"\n";
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		
		str += sprintf("ȷ��:usesxidian -yes" + ZJSEP);
		str += sprintf("ȡ��: ");
		tell_object(me, str + "\n");
		return 1;
	} else if(arg == "-yes") {
		max_sx = (me->query("con") + me->query("dex")+me->query("int")+me->query("str"))
					-(me->query("gift/shenliwan") + me->query("gift/xiandan")+me->query("gift/unknowdan")+me->query("gift/lighting") +me->query("gift/xisuidan"))
					-(me->query("level")/10-me->query("tianfu_point"));
		
		write(INPUTTXT(HIR"ע��ֵ������13-45֮��"ZJBR"�ܺͲ��ܳ��������е�����"+max_sx+"�㡣"
											+NOR+ZJBR+HIW+"(���� ���� ���� ��)"
											+NOR+ZJBR+HIY+"(����20 20 20 20���м��Կո����)"+NOR+
												ZJBR+"�������������������","usesxidian $txt#")+"\n");
	} else if(sscanf(arg, "-yes %d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) == 4) {
		if (tmpstr < 30 || tmpstr >45
			|| tmpint < 30 || tmpint >45
			|| tmpcon < 30 || tmpcon >45
			|| tmpdex < 30 || tmpdex >45) {
				write(HIR"����һ�����벻��(30-45)��Χ֮�ڡ�"NOR"\n");
				return 1;
			}
		my = me->query_entire_dbase();
		max_sx = (my["con"] + my["dex"]+my["int"]+my["str"])
					-(me->query("gift/shenliwan") + me->query("gift/xiandan")+me->query("gift/unknowdan")+me->query("gift/lighting") +me->query("gift/xisuidan"))
					-(my["level"]/10-my["tianfu_point"]);
			
		if (tmpstr+ tmpint+ tmpcon+ tmpdex != max_sx) {
			write(HIR"���������������������Ŀǰ�����������ԡ�"NOR"\n");
			return 1;
		}
		
		line = sprintf("str(%d)int(%d)con(%d)dex(%d)", tmpstr, tmpint, tmpcon, tmpdex);
		
		tmpstr += me->query("gift/shenliwan");
		tmpint += me->query("gift/xiandan");
		tmpcon += me->query("gift/unknowdan")+me->query("gift/lighting");
		tmpdex += me->query("gift/xisuidan");
		max_sx2 = tmpstr+ tmpint+ tmpcon+ tmpdex;
		
		my["str"]= tmpstr;
		my["int"]= tmpint;
		my["con"]= tmpcon;
		my["dex"]= tmpdex;
		my["tianfu_point"] = my["level"] /10;
		
		CHANNEL_D->do_channel( this_object(), "chat", "��˵"+me->name()+"��ϴ�㿨���������壡");
		message_vision(HIY"$Nʹ����һ"+query("unit") + name() + HIY "�����������壡"NOR"\n", me);
		tell_object(me, HIY"�������ܳɹ������ٲ�������һ���츳��"NOR"\n");
		
		//�����������ļ����Ƿ����Ҫ�󣬲����ϵ�ɾ��
		UPDATE_D->check_skill(me);
		me->set("usesxidian", time());
		me->save();
		log_file("/cmds/xidian", sprintf("%s  ϴ��=%s  �ܼ�=str(%d)int(%d)con(%d)dex(%d) �ܹ�(%d/%d��) ϴ��ʱ�䣺%s\n", 
											me->name()+"("+my["id"]+")", line, tmpstr, tmpint, tmpcon, tmpdex, max_sx, max_sx2, CHINESE_D->chinese_date(time(), 2)));
		add_amount(-1);
	} else if(sscanf(arg, "%d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) == 4) {
		
		str = ZJOBLONG+ HIC"������ã�"HIG"����("+tmpstr+") ����("+tmpint+") ����("+tmpcon+") ��("+tmpdex+")"NOR
				+ZJBR"��������·�������������"ZJBR+HIR+ZJSIZE(24)
										+"������ѡ�����һ�����ѣ�һ��ϴ�㣬�����ɻָ���"NOR"\n";
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		
		str += sprintf("ȷ��:usesxidian -yes " +tmpstr+" "+ tmpint+" "+ tmpcon+" "+ tmpdex+ ZJSEP);
		str += sprintf("ȡ��: ");
		tell_object(me, str + "\n");
	} else 
		me->force_me("usesxidian");
	return 1;
}	 
