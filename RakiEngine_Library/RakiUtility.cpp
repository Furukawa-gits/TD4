#include "RakiUtility.h"

int rutility::GetDigits(float value, int left, int right)
{
    double mod_value;
    int result;

    /* ���O�ɐ�Βl�����߂Ă��� */
    value = fabs(value);

    /* n���ڈȉ��̌����擾 */
    mod_value = fmod(value, pow(10, right + 1));

    /* m���ڈȏ�̌����擾 */
    result = int(mod_value / pow(10, left));

    return result;
}
