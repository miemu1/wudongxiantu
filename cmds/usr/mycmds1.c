// mudage.c
//[xiaojl 1999/11/20 ����II]

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int min, hrs, day, mon, age;
		string sec;
        string out_str;
    	sec = sprintf(HIY"  �� �Թ�̽�� �� "NOR"\n");
if (!me->query("migong/lev1"))
    	sec += sprintf(HIR"  �Թ��� һ �� ��δ��ɡ�    "NOR" \n");
else
    	sec += sprintf(HIC"  �Թ��� һ �� �� ��� ��  "NOR"   \n");
if (!me->query("migong/lev2"))
    	sec += sprintf(HIR"  �Թ��� �� �� ��δ��ɡ�  "NOR"   \n");
else
    	sec += sprintf(HIC"  �Թ��� �� �� �� ��� ��    "NOR"  \n");
if (!me->query("migong/lev3"))
    	sec += sprintf(HIR"  �Թ��� �� �� ��δ��ɡ�   "NOR"   \n");
else
    	sec += sprintf(HIC"  �Թ��� �� �� �� ��� ��   "NOR"   \n");
if (!me->query("migong/lev4" ))
    	sec += sprintf(HIR"  �Թ��� �� �� ��δ��ɡ�   "NOR"   \n");
else
    	sec += sprintf(HIC"  �Թ��� �� �� �� ��� �� "NOR"\n");
if (!me->query("migong/lev5"))
    	sec += sprintf(HIR"  �Թ��� �� �� ��δ��ɡ�  "NOR"    \n");
else
    	sec += sprintf(HIC"  �Թ��� �� �� �� ��� ��    "NOR"  \n");
if (!me->query("migong/lev6"))
    	sec += sprintf(HIR"  �Թ��� �� �� ��δ��ɡ� "NOR"     \n");
else
    	sec += sprintf(HIC"  �Թ��� �� �� �� ��� ��    "NOR"  \n");
if (!me->query("migong/lev7"))
    	sec += sprintf(HIR"  �Թ��� �� �� ��δ��ɡ�  "NOR"    \n");
else
    	sec += sprintf(HIC"  �Թ��� �� �� �� ��� ��    "NOR"  \n");
if (!me->query("migong/lev8"))
    	sec += sprintf(HIR"  �Թ��� �� �� ��δ��ɡ�   "NOR"   \n");
else
    	sec += sprintf(HIC"  �Թ��� �� �� �� ��� ��  "NOR"    \n");
if (!me->query("migong/lev9"))
    	sec += sprintf(HIR"  �Թ��� �� �� ��δ��ɡ�   "NOR"   \n");
else
    	sec += sprintf(HIC"  �Թ��� �� �� �� ��� �� "NOR"     \n");
if (!me->query("migong/lev10"))
    	sec += sprintf(HIR"  �Թ��� ʮ �� ��δ��ɡ�  "NOR"    \n");
else
    	sec += sprintf(HIC"  �Թ��� ʮ �� �� ��� ��   "NOR"   \n");
if (!me->query("migong/lev11"))
    	sec += sprintf(HIR"  �Թ���ʮһ�� ��δ��ɡ� "NOR"     \n");
else
    	sec += sprintf(HIC"  �Թ���ʮһ�� �� ��� ��  "NOR"    \n");
if (!me->query("migong/lev12"))
    	sec += sprintf(HIR"  �Թ���ʮ���� ��δ��ɡ�  "NOR"    \n");
else
    	sec += sprintf(HIC"  �Թ���ʮ���� �� ��� ��    "NOR"  \n");
if (!me->query("migong/lev13"))
    	sec += sprintf(HIR"  �Թ���ʮ���� ��δ��ɡ�  "NOR"    \n");
else
    	sec += sprintf(HIC"  �Թ���ʮ���� �� ��� ��     "NOR" \n");
if (!me->query("migong/lev14"))
    	sec += sprintf(HIR"  �Թ���ʮ�Ĳ� ��δ��ɡ�  "NOR"    \n");
else
    	sec += sprintf(HIC"  �Թ���ʮ�Ĳ� �� ��� ��      "NOR"\n");
if (!me->query("migong/lev15"))
    	sec += sprintf(HIR"  �Թ���ʮ��� ��δ��ɡ�  "NOR"    \n");
else
    	sec += sprintf(HIC"  �Թ���ʮ��� �� ��� ��     "NOR"\n");
    	
    	

if ((int)me->query("szj/failed")>3)
    	sec += sprintf(HIR"  ����:���վ�  ��ʧ�ܡ�   "NOR"   \n");
if ((int)me->query("szj/passed"))
    	sec += sprintf(HIC"  ����:���վ�  ���ɹ���  "NOR"    \n");
if ((int)me->query("jiuyin/shang-failed")>2)
    	sec += sprintf(HIR"  ����:������  ��ʧ�ܡ�   "NOR"   \n");
if ((int)me->query("jiuyin/shang"))
    	sec += sprintf(HIC"  ����:������  ���ɹ���    "NOR"  \n");
if ((int)me->query("jiuyin/xia-failed")>2)
    	sec += sprintf(HIR"  ����:������  ��ʧ�ܡ�  "NOR"    \n");
if ((int)me->query("jiuyin/xia"))
    	sec += sprintf(HIC"  ����:������  ���ɹ���     "NOR" \n");
if ((int)me->query("jiuyin/emei"))
    	sec += sprintf(HIC"  ����:�����ٳɡ��ɹ��� "NOR"     \n");
if ((int)me->query("jiuyin/full"))
    	sec += sprintf(HIC"  ����:����ȫ�����ɹ���   "NOR"   \n");
if ((int)me->query("double_attack"))
    	sec += sprintf(HIC"  ����:˫�ֻ������ɹ���    "NOR"  \n");
if ((int)me->query("jiuyin/gumu-failed")>2)
    	sec += sprintf(HIR"  ����:������Ĺ��ʧ�ܡ�   "NOR"   \n");
if ((int)me->query("zhou/failed")>2)
    	sec += sprintf(HIR"  ����:��  ��  ��ʧ�ܡ�   "NOR"   \n");
if ((int)me->query("zhou/fail")>2)
    	sec += sprintf(HIR"  ����:��  ��  ��ʧ�ܡ�    "NOR"  \n");
if ((int)me->query("zhou/jieyi")>2)
    	sec += sprintf(HIR"  ����:�������塺ʧ�ܡ�   "NOR"   \n");

		sec = replace_string(sec,"\n",ZJBR)+"\n";
		write(ZJOBLONG+sec+"\n");

        return 1;
}


int help(object me)
{
	string sec;
	sec = sprintf(WHT"\n���Թ�Ѱ������"NOR"\n");
	sec += sprintf(@HELP
������,��ҿ���ȥ�Թ�Ѱ��.λ����������������ʯ�߽��룬�Թ���15��,������quest�Ͳ�������.
ÿ����Щ����,�ͱ���,��ҿ���kill ����,��openbox����
�򿪱��䱦���еı����������,�����к���ͨ�Ķ���,Ҳ
�������������,�书����, ������Ϊ���exp,pot,neili,
�ڵ�5�����µ��Թ����ڱ���������ҵ�  ������  ����
������� ���� ��Ե�� ��ò�������������ҵ���,���
����eat������,��exp,pot.�������ȫ��������,������
hebing���ϲ�����,���100000exp, 1000000pot,500 neili�������.(�򿪱���,Ҳ�������,�ж��Ŀ���)
���౦��˵��
������->ɽ��
������->����ʯ��
������->�Ҷ�
����->���Ҷ�
��Ե��->���Ҷ�
��ò��->�Ҷ�
��ȫ�����hebing��eat
������->ɽ��
������->����ʯ��
������->�Ҷ�
������->���Ҷ�
ˮ����->�Ҷ�
�ҵ������wear,�о޴�ս��Ч��
�����ȫ�Ļ����Է������ˮ����ϱ�(wuzhuhebi)
�ϳ�ʥ����

    �ں��漸����boss�ػ�,���֮,�ɻ�exp,pot

    �����һ���л����ػ�,
    ���ǧ�����,�ɻ�ǧ������ף�������2000��
    �����ͨ����,�ɻ�����ף�������1000��

    �ڵ�6-12�㣬������һ���ط���������newup����
���ﴫ˵�е�ʥ�������������ս��12�ƽ�վʿ��ÿ
���һ�ˣ��ɻ���Ϊ20000�����ȫ����ܣ��ɻ�ƽ�
ʥ��һ��(������1200)��������Ϊ��Ǳ�ܡ�

 ע:1.������Σ�ռ���....
    2.��������ü�����teamȥ��....
    3.��������exp>100000exp
	4.ɱ�г�exp,pot�������
    lev1 exp < 200000
    lev2  300000
    lev3  700000
    lev4  1000000
    lev5  1500000
    lev6  2500000
    lev7  3000000
    lev8  3500000
    lev9  4500000
    lev10 6000000
    lev11 8000000
    lev12 9000000
    lev13 10000000
    lev14 12000000-15000000
    lev15 16000000-18000000

�������:openbox(������)mgmap(��ʾ������ͼ)
������2ת����Ϊ�ﵽ20M,���������������ʦ���3תҪ��
3ת��,ֻ�������ԣ��͵��ߡ������Խ����Թ�16���Ժ��6�����磬
������ѧϰ���е��µļ��ܣ������������ϰ��ֵ��ˣ��ϰ��ֵ��ߣ�������������!!
HELP
	);

		sec = replace_string(sec,"\n",ZJBR)+"\n";
		write(ZJOBLONG+sec+"\n");
	return 1;
}