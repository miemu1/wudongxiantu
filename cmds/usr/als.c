// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
	    object obj,ob,obj1,obj2,obj3,obj4;
	mapping alias;
        int count,mengxin,i;
        string a,b;
	string verb, replace, *vrbs,str;

		me = this_player();
        if (! arg) 
		
        return notify_fail(INPUTTXT(ZJSIZE(18)MAG BBLK"��ѡ����Ҫ����10�εĿ��ָ��"NOR,"als $txt#")+"\n");
		
	switch (arg) {
	  case "1" :
			str = ZJOBLONG+ZJSIZE(29)+WHT"ע�⣺�������50%�ĳɹ��ʣ����������������֮ǰʧ��ֻ��۳�һ��������ϣ�֮��ʧ��ֻ��۳����ֲ��ϣ�"+NOR+ZJBR+sprintf(HIR"��Ŀǰ����������ȼ�Ϊ��" NOR + HIY " %d��"NOR, me->query("weapon/dj"))+ZJBR+sprintf(HIR"��Ŀǰ���������ȼ�Ϊ��" NOR + HIY " %d��"NOR"\n", me->query("shenbing/dj"))+"\n"+ZJOBACTS2+ZJMENUF(1,1,10,29);
			str += "���������Ҫִ��ʮ����ָ����磺aa:als"+ZJSEP;
			write(str+"\n");
		return 1;

		break;
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

int help(object me)
{
        write(@HELP
ָ���ʽ��giveall ��Ʒ·��

�����ߵ�������Һ����
HELP
        );
        return 1;
}
