#include "stdafx.h"

#include "stdlib.h"

#include "internal.h"

#include "corecrt_internal_securecrt.h"

namespace STLight
{
	namespace
	{
		template <typename T> struct make_signed;
		template <> struct make_signed<unsigned long> { typedef long    type; };
		//template <> struct make_signed<unsigned __int64> { typedef __int64 type; };
	}

	template <typename UnsignedInteger, typename Character>
	_Success_(return == 0)
		static errno_t __cdecl common_xtox(
			UnsignedInteger const   original_value,
			_Out_writes_z_(buffer_count)    Character*      const   buffer,
			_When_(is_negative == true, _In_range_(>= , 2)) _In_range_(>= , 1)
			size_t          const   buffer_count,
			unsigned        const   radix,
			bool            const   is_negative
			) throw()
	{
		Character* p = buffer; // pointer to traverse the string
		size_t     length = 0;      // current length of string

		UnsignedInteger remaining_value = original_value;;

		if (is_negative)
		{
			*p++ = '-';
			++length;

			remaining_value = static_cast<UnsignedInteger>(
				-static_cast<typename make_signed<UnsignedInteger>::type>(remaining_value)
				);
		}

		Character* first_digit = p;

		do
		{
			unsigned const digit = static_cast<unsigned>(remaining_value % radix);
			remaining_value /= radix;

			// Convert to ASCII and store:
			if (digit > 9)
			{
				*p++ = static_cast<Character>(digit - 10 + 'a');
			}
			else
			{
				*p++ = static_cast<Character>(digit + '0');
			}

			++length;
		} while (remaining_value > 0 && length < buffer_count);

		if (length >= buffer_count)
		{
			buffer[0] = '\0';
			_VALIDATE_RETURN_ERRCODE(length < buffer_count, ERANGE);
		}

		// We now have the digits of the number in the buffer, but in reverse order.
		// Reverse the order, but first terminate the string:
		*p-- = '\0';

		do
		{
			Character const t = *p;
			*p = *first_digit;
			*first_digit = t;
			--p;
			++first_digit;
		} while (first_digit < p);

		return 0;
	}

	template <typename UnsignedInteger, typename Character>
	_Success_(return == 0)
		static errno_t __cdecl common_xtox_s(
			UnsignedInteger const   value,
			_Out_writes_z_(buffer_count)    Character*      const   buffer,
			size_t          const   buffer_count,
			unsigned        const   radix,
			bool            const   is_negative
			) throw()
	{
		_VALIDATE_RETURN_ERRCODE(buffer != nullptr, EINVAL);
		_VALIDATE_RETURN_ERRCODE(buffer_count > 0, EINVAL);
		_RESET_STRING(buffer, buffer_count);
		_VALIDATE_RETURN_ERRCODE(buffer_count > static_cast<size_t>(is_negative ? 2 : 1), ERANGE);
		_VALIDATE_RETURN_ERRCODE(2 <= radix && radix <= 36, EINVAL);

		return common_xtox(value, buffer, buffer_count, radix, is_negative);
	}

	extern "C" errno_t __cdecl _itoa_s(
		int    const value,
		char*  const buffer,
		size_t const buffer_count,
		int    const radix
		)
	{
		bool const is_negative = radix == 10 && value < 0;
		return common_xtox_s(static_cast<unsigned long>(value), buffer, buffer_count, radix, is_negative);
	}
}