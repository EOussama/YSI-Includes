#if defined _INC_Y_COLOURSPACE
	#endinput
#endif
#define _INC_Y_COLOURSPACE

// Available colour spaces:
//
//   * `RGB:` - No alpha.
//   * `RGBA:` - Alpha last.
//   * `ARGB:` - Alpha first.
//   * `HSI:` - Hue, Saturation, Intensity
//   * `HSIA:` - Hue, Saturation, Intensity, Alpha
//   * `AHSI:` - Alpha, Hue, Saturation, Intensity
//   * `HSL:` - Hue, Saturation, Lightness
//   * `HSLA:` - Hue, Saturation, Lightness, Alpha
//   * `AHSL:` - Alpha, Hue, Saturation, Lightness
//   * `HSV:` - Hue, Saturation, Value
//   * `HSVA:` - Hue, Saturation, Value, Alpha
//   * `AHSV:` - Alpha, Hue, Saturation, Value
//

#define YUC_GetR(%0:%1) YUC_GetR_%0(%1)
#define YUC_GetG(%0:%1) YUC_GetG_%0(%1)
#define YUC_GetB(%0:%1) YUC_GetB_%0(%1)
#define YUC_GetA(%0:%1) YUC_GetA_%0(%1)

#define YUC_GetR_RGB(%1) (((_:(%1)) >>> 16) & 0xFF)
#define YUC_GetG_RGB(%1) (((_:(%1)) >>>  8) & 0xFF)
#define YUC_GetB_RGB(%1) (((_:(%1))       ) & 0xFF)
#define YUC_GetA_RGB(%1) (0)

#if cellbits == 64
	#define YUC_GetR_RGBA(%1) (((_:(%1)) >>> 24) & 0xFF)
#else
	#define YUC_GetR_RGBA(%1) (((_:(%1)) >>> 24))
#endif
#define YUC_GetG_RGBA(%1) (((_:(%1)) >>> 16) & 0xFF)
#define YUC_GetB_RGBA(%1) (((_:(%1)) >>>  8) & 0xFF)
#define YUC_GetA_RGBA(%1) (((_:(%1))       ) & 0xFF)

#define YUC_GetR_ARGB(%1) (((_:(%1)) >>> 16) & 0xFF)
#define YUC_GetG_ARGB(%1) (((_:(%1)) >>>  8) & 0xFF)
#define YUC_GetB_ARGB(%1) (((_:(%1))       ) & 0xFF)
#if cellbits == 64
	#define YUC_GetA_ARGB(%1) (((_:(%1)) >>> 24) & 0xFF)
#else
	#define YUC_GetA_ARGB(%1) (((_:(%1)) >>> 24))
#endif

#define YUC_SetR(%0:%1) YUC_SetR_%0(%1)
#define YUC_SetG(%0:%1) YUC_SetG_%0(%1)
#define YUC_SetB(%0:%1) YUC_SetB_%0(%1)
#define YUC_SetA(%0:%1) YUC_SetA_%0(%1)

#define YUC_SetR_RGB(%1) (((%1) & 0xFF) << 16)
#define YUC_SetG_RGB(%1) (((%1) & 0xFF) <<  8)
#define YUC_SetB_RGB(%1) (((%1) & 0xFF)      )
#define YUC_SetA_RGB(%1) (0)

#define YUC_SetR_RGBA(%1) (((%1) & 0xFF) << 24)
#define YUC_SetG_RGBA(%1) (((%1) & 0xFF) << 16)
#define YUC_SetB_RGBA(%1) (((%1) & 0xFF) <<  8)
#define YUC_SetA_RGBA(%1) (((%1) & 0xFF)      )

#define YUC_SetR_ARGB(%1) (((%1) & 0xFF) << 16)
#define YUC_SetG_ARGB(%1) (((%1) & 0xFF) <<  8)
#define YUC_SetB_ARGB(%1) (((%1) & 0xFF)      )
#define YUC_SetA_ARGB(%1) (((%1) & 0xFF) << 24)

// The `HSX` values are stored in following format:
//
//   (H * 3.0) * 101 * 101 + (S * 100.0) * 101 + (X * 100.0)
//
// This expands `S` and `X` from `0-1` to `0-100`, and allows storing 20 minute
// increments for `H`.

#define YUC_GetH(%0:%1) YUC_GetH_%0(%1)
#define YUC_GetS(%0:%1) YUC_GetS_%0(%1)
#define YUC_GetX(%0:%1) YUC_GetX_%0(%1)
#define YUC_GetA(%0:%1) YUC_GetA_%0(%1)

#define YUC_GetH_HSX(%1) (float((_:(%1)) / 10201      ) /   3.0)
#define YUC_GetS_HSX(%1) (float((_:(%1)) /   101 % 101) / 100.0)
#define YUC_GetX_HSX(%1) (float((_:(%1))         % 101) / 100.0)
#define YUC_GetA_HSX(%1) (0)

// We could combine the `>>>` and `/` stages with `/ 2560000`, but then we have
// to worry about signs.  This just solves it easily.
#define YUC_GetH_HSXA(%1) (float(((_:(%1)) >>> 8) / 10201      ) /   3.0)
#define YUC_GetS_HSXA(%1) (float(((_:(%1)) >>> 8) /   101 % 101) / 100.0)
#define YUC_GetX_HSXA(%1) (float(((_:(%1)) >>> 8)         % 101) / 100.0)
#define YUC_GetA_HSXA(%1) ((_:(%1)) & 0xFF)

#define YUC_GetH_AHSX(%1) (float(((_:(%1)) & 0xFFFFFF) / 10201      ) /   3.0)
#define YUC_GetS_AHSX(%1) (float(((_:(%1)) & 0xFFFFFF) /   101 % 101) / 100.0)
#define YUC_GetX_AHSX(%1) (float(((_:(%1)) & 0xFFFFFF)         % 101) / 100.0)
#if cellbits == 64
	#define YUC_GetA_AHSX(%1) (((_:(%1)) >>> 24) & 0xFF)
#else
	#define YUC_GetA_AHSX(%1) ((_:(%1)) >>> 24)
#endif

#define YUC_SetH(%0:%1) YUC_SetH_%0(%1)
#define YUC_SetS(%0:%1) YUC_SetS_%0(%1)
#define YUC_SetX(%0:%1) YUC_SetX_%0(%1)
#define YUC_SetA(%0:%1) YUC_SetA_%0(%1)

#define YUC_SetH_HSX(%1) (floatround((%1) * 3.0) * 10201)
#define YUC_SetS_HSX(%1) (floatround((%1) * 100.0) * 101)
#define YUC_SetX_HSX(%1) (floatround((%1) * 100.0)      )
#define YUC_SetA_HSX(%1) (0)

#define YUC_SetH_HSXA(%1) ((floatround((%1) * 3.0) * 10201) << 8)
#define YUC_SetS_HSXA(%1) ((floatround((%1) * 100.0) * 101) << 8)
#define YUC_SetX_HSXA(%1) ((floatround((%1) * 100.0)      ) << 8)
#define YUC_SetA_HSXA(%1) ((%1) & 0xFF)

#define YUC_SetH_AHSX(%1) (floatround((%1) * 3.0) * 10201)
#define YUC_SetS_AHSX(%1) (floatround((%1) * 100.0) * 101)
#define YUC_SetX_AHSX(%1) (floatround((%1) * 100.0)      )
#define YUC_SetA_AHSX(%1) (((%1) & 0xFF) << 24)

#define YUC_Min(%0,%1,%2) min(min((%0), (%1)), (%2))
#define YUC_Max(%0,%1,%2) max(max((%0), (%1)), (%2))

stock YUC_RGBToHSI(r, g, b, &Float:h, &Float:s, &Float:i)
{
	// We could use `max` here, but we also need to know which was the answer.
	new
		Float:fr = r / 255.0,
		Float:fg = g / 255.0,
		Float:fb = b / 255.0;
	if (r == g && g == b)
	{
		// Special case.
		h = 0.0,
		i = rg,
		s = 0.0;
	}
	else
	{
		new
			Float:c;
		if (r > g)
		{
			if (b > r) // b > r > g
			{
				// b largest, g smallest.
				c = fb - fg,
				h = 60.0 * ((fr - fg) / c + 4.0),
				i = (fr + rg + fb) / 3.0,
				s = i <= 0.0 ? 0.0 : 1 - rg / i;
			}
			else if (b > g) // r >= b > g
			{
				// r largest, g smallest.
				c = fr - fg,
				h = 60.0 * ((fg - fb) / c + 6.0),
				i = (fr + rg + fb) / 3.0,
				s = i <= 0.0 ? 0.0 : 1 - rg / i;
			}
			else // r > g >= b
			{
				// r largest, b smallest.
				c = fr - fb,
				h = 60.0 * ((fg - fb) / c),
				i = (fr + rg + fb) / 3.0,
				s = i <= 0.0 ? 0.0 : 1 - rb / i;
			}
		}
		else
		{
			if (b > g) // b > g >= r
			{
				// b largest, r smallest.
				c = fb - fr,
				h = 60.0 * ((fr - fg) / c + 4.0),
				i = (fr + rg + fb) / 3.0,
				s = i <= 0.0 ? 0.0 : 1 - rr / i;
			}
			else if (b > r) // g >= b > r
			{
				// g largest, r smallest.
				c = fg - fr,
				h = 60.0 * ((fb - fr) / c + 2.0),
				i = (fr + rg + fb) / 3.0,
				s = i <= 0.0 ? 0.0 : 1 - rr / i;
			}
			else // g >= r >= b
			{
				// g largest, b smallest.
				c = fg - fb,
				h = 60.0 * ((fb - fr) / c + 2.0),
				i = (fr + rg + fb) / 3.0,
				s = i <= 0.0 ? 0.0 : 1 - rb / i;
				// We could handle the special case here, since `r == g == b` is a
				// subset of `g >= r >= b`, but better to separate it.
			}
		}
	}
}

stock YUC_RGBToHSV(r, g, b, &Float:h, &Float:s, &Float:v)
{
	// We could use `max` here, but we also need to know which was the answer.
	new
		Float:fr = r / 255.0,
		Float:fg = g / 255.0,
		Float:fb = b / 255.0;
	if (r == g && g == b)
	{
		// Special case.
		h = 0.0,
		v = fg,
		s = 0.0;
	}
	else
	{
		new
			Float:c;
		if (r > g)
		{
			if (b > r) // b > r > g
			{
				// b largest, g smallest.
				c = fb - fg,
				h = 60.0 * ((fr - fg) / c + 4.0),
				v = fb;
			}
			else if (b > g) // r >= b > g
			{
				// r largest, g smallest.
				c = fr - fg,
				h = 60.0 * ((fg - fb) / c + 6.0),
				v = fr;
			}
			else // r > g >= b
			{
				// r largest, b smallest.
				c = fr - fb,
				h = 60.0 * ((fg - fb) / c),
				v = fr;
			}
		}
		else
		{
			if (b > g) // b > g >= r
			{
				// b largest, r smallest.
				c = fb - fr,
				h = 60.0 * ((fr - fg) / c + 4.0),
				v = fb;
			}
			else if (b > r) // g >= b > r
			{
				// g largest, r smallest.
				c = fg - fr,
				h = 60.0 * ((fb - fr) / c + 2.0),
				v = fg;
			}
			else // g >= r >= b
			{
				// g largest, b smallest.
				c = fg - fb,
				h = 60.0 * ((fb - fr) / c + 2.0),
				v = fg;
				// We could handle the special case here, since `r == g == b` is a
				// subset of `g >= r >= b`, but better to separate it.
			}
		}
		s = v <= 0.0 ? 0.0 : c / v;
	}
}

stock YUC_RGBToHSL(r, g, b, &Float:h, &Float:s, &Float:l)
{
	// We could use `max` here, but we also need to know which was the answer.
	new
		Float:fr = r / 255.0,
		Float:fg = g / 255.0,
		Float:fb = b / 255.0;
	if (r == g && g == b)
	{
		// Special case.
		h = 0.0,
		l = fb,
		s = 0.0;
	}
	else
	{
		new
			Float:c;
		if (r > g)
		{
			if (b > r) // b > r > g
			{
				// b largest, g smallest.
				c = fb - fg,
				h = 60.0 * ((fr - fg) / c + 4.0),
				l = (fb + fg) / 2.0;
			}
			else if (b > g) // r >= b > g
			{
				// r largest, g smallest.
				c = fr - fg,
				h = 60.0 * ((fg - fb) / c + 6.0),
				l = (fr + fg) / 2.0;
			}
			else // r > g >= b
			{
				// r largest, b smallest.
				c = fr - fb,
				h = 60.0 * ((fg - fb) / c),
				l = (fr + fb) / 2.0;
				printf("yes: %.2f, %.2f, %.2f", c, h, l);
				printf("yes: %.2f, %.2f, %.2f", (fg - fb), (fg - fb) / c, 60.0 * ((fg - fb) / c));
			}
		}
		else
		{
			if (b > g) // b > g >= r
			{
				// b largest, r smallest.
				c = fb - fr,
				h = 60.0 * ((fr - fg) / c + 4.0),
				l = (fb + fr) / 2.0;
			}
			else if (b > r) // g >= b > r
			{
				// g largest, r smallest.
				c = fg - fr,
				h = 60.0 * ((fb - fr) / c + 2.0),
				l = (fg + fr) / 2.0;
			}
			else // g >= r >= b
			{
				// g largest, b smallest.
				c = fg - fb,
				h = 60.0 * ((fb - fr) / c + 2.0),
				l = (fg + fb) / 2.0;
				// We could handle the special case here, since `r == g == b` is a
				// subset of `g >= r >= b`, but better to separate it.
			}
		}
		s = l <= 0.0 || l >= 1.0 ? 0.0 : c / (1.0 - floatabs(2.0 * l - 1.0));
		printf("h = %.2f", h);
		printf("s = %.2f", s);
		printf("l = %.2f", l);
	}
}

stock RGB:operator=(_:value)
{
	return RGB:value;
}

stock RGBA:operator=(_:value)
{
	return RGBA:value;
}

stock ARGB:operator=(_:value)
{
	return ARGB:value;
}

stock HSI:operator=(RGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSI(YUC_GetR(RGB:value), YUC_GetG(RGB:value), YUC_GetB(RGB:value), h, s, l);
	return HSI:(YUC_SetH(HSX:h) + YUC_SetS(HSX:s) + YUC_SetX(HSX:l));
}

stock HSIA:operator=(RGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSI(YUC_GetR(RGB:value), YUC_GetG(RGB:value), YUC_GetB(RGB:value), h, s, l);
	return HSIA:((YUC_SetH(HSXA:h) + YUC_SetS(HSXA:s) + YUC_SetX(HSXA:l)) | YUC_SetA(HSXA:255));
}

stock AHSI:operator=(RGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSI(YUC_GetR(RGB:value), YUC_GetG(RGB:value), YUC_GetB(RGB:value), h, s, l);
	return AHSI:((YUC_SetH(AHSX:h) + YUC_SetS(AHSX:s) + YUC_SetX(AHSX:l)) | YUC_SetA(AHSX:255));
}

stock HSI:operator=(RGBA:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSI(YUC_GetR(RGBA:value), YUC_GetG(RGBA:value), YUC_GetB(RGBA:value), h, s, l);
	return HSI:(YUC_SetH(HSX:h) + YUC_SetS(HSX:s) + YUC_SetX(HSX:l));
}

stock HSIA:operator=(RGBA:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSI(YUC_GetR(RGBA:value), YUC_GetG(RGBA:value), YUC_GetB(RGBA:value), h, s, l);
	return HSIA:((YUC_SetH(HSXA:h) + YUC_SetS(HSXA:s) + YUC_SetX(HSXA:l)) | YUC_SetA(HSXA:YUC_GetA(RGBA:value)));
}

stock AHSI:operator=(RGBA:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSI(YUC_GetR(RGBA:value), YUC_GetG(RGBA:value), YUC_GetB(RGBA:value), h, s, l);
	return AHSI:((YUC_SetH(AHSX:h) + YUC_SetS(AHSX:s) + YUC_SetX(AHSX:l)) | YUC_SetA(AHSX:YUC_GetA(RGBA:value)));
}

stock HSI:operator=(ARGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSI(YUC_GetR(ARGB:value), YUC_GetG(ARGB:value), YUC_GetB(ARGB:value), h, s, l);
	return HSI:(YUC_SetH(HSX:h) + YUC_SetS(HSX:s) + YUC_SetX(HSX:l));
}

stock HSIA:operator=(ARGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSI(YUC_GetR(ARGB:value), YUC_GetG(ARGB:value), YUC_GetB(ARGB:value), h, s, l);
	return HSIA:((YUC_SetH(HSXA:h) + YUC_SetS(HSXA:s) + YUC_SetX(HSXA:l)) | YUC_SetA(HSXA:YUC_GetA(ARGB:value)));
}

stock AHSI:operator=(ARGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSI(YUC_GetR(ARGB:value), YUC_GetG(ARGB:value), YUC_GetB(ARGB:value), h, s, l);
	return AHSI:((YUC_SetH(AHSX:h) + YUC_SetS(AHSX:s) + YUC_SetX(AHSX:l)) | YUC_SetA(AHSX:YUC_GetA(ARGB:value)));
}

stock HSV:operator=(RGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSV(YUC_GetR(RGB:value), YUC_GetG(RGB:value), YUC_GetB(RGB:value), h, s, l);
	return HSV:(YUC_SetH(HSX:h) + YUC_SetS(HSX:s) + YUC_SetX(HSX:l));
}

stock HSVA:operator=(RGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSV(YUC_GetR(RGB:value), YUC_GetG(RGB:value), YUC_GetB(RGB:value), h, s, l);
	return HSVA:((YUC_SetH(HSXA:h) + YUC_SetS(HSXA:s) + YUC_SetX(HSXA:l)) | YUC_SetA(HSXA:255));
}

stock AHSV:operator=(RGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSV(YUC_GetR(RGB:value), YUC_GetG(RGB:value), YUC_GetB(RGB:value), h, s, l);
	return AHSV:((YUC_SetH(AHSX:h) + YUC_SetS(AHSX:s) + YUC_SetX(AHSX:l)) | YUC_SetA(AHSX:255));
}

stock HSV:operator=(RGBA:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSV(YUC_GetR(RGBA:value), YUC_GetG(RGBA:value), YUC_GetB(RGBA:value), h, s, l);
	return HSV:(YUC_SetH(HSX:h) + YUC_SetS(HSX:s) + YUC_SetX(HSX:l));
}

stock HSVA:operator=(RGBA:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSV(YUC_GetR(RGBA:value), YUC_GetG(RGBA:value), YUC_GetB(RGBA:value), h, s, l);
	return HSVA:((YUC_SetH(HSXA:h) + YUC_SetS(HSXA:s) + YUC_SetX(HSXA:l)) | YUC_SetA(HSXA:YUC_GetA(RGBA:value)));
}

stock AHSV:operator=(RGBA:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSV(YUC_GetR(RGBA:value), YUC_GetG(RGBA:value), YUC_GetB(RGBA:value), h, s, l);
	return AHSV:((YUC_SetH(AHSX:h) + YUC_SetS(AHSX:s) + YUC_SetX(AHSX:l)) | YUC_SetA(AHSX:YUC_GetA(RGBA:value)));
}

stock HSV:operator=(ARGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSV(YUC_GetR(ARGB:value), YUC_GetG(ARGB:value), YUC_GetB(ARGB:value), h, s, l);
	return HSV:(YUC_SetH(HSX:h) + YUC_SetS(HSX:s) + YUC_SetX(HSX:l));
}

stock HSVA:operator=(ARGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSV(YUC_GetR(ARGB:value), YUC_GetG(ARGB:value), YUC_GetB(ARGB:value), h, s, l);
	return HSVA:((YUC_SetH(HSXA:h) + YUC_SetS(HSXA:s) + YUC_SetX(HSXA:l)) | YUC_SetA(HSXA:YUC_GetA(ARGB:value)));
}

stock AHSV:operator=(ARGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSV(YUC_GetR(ARGB:value), YUC_GetG(ARGB:value), YUC_GetB(ARGB:value), h, s, l);
	return AHSV:((YUC_SetH(AHSX:h) + YUC_SetS(AHSX:s) + YUC_SetX(AHSX:l)) | YUC_SetA(AHSX:YUC_GetA(ARGB:value)));
}

stock HSL:operator=(RGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSL(YUC_GetR(RGB:value), YUC_GetG(RGB:value), YUC_GetB(RGB:value), h, s, l);
	return HSL:(YUC_SetH(HSX:h) + YUC_SetS(HSX:s) + YUC_SetX(HSX:l));
}

stock HSLA:operator=(RGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSL(YUC_GetR(RGB:value), YUC_GetG(RGB:value), YUC_GetB(RGB:value), h, s, l);
	return HSLA:((YUC_SetH(HSXA:h) + YUC_SetS(HSXA:s) + YUC_SetX(HSXA:l)) | YUC_SetA(HSXA:255));
}

stock AHSL:operator=(RGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSL(YUC_GetR(RGB:value), YUC_GetG(RGB:value), YUC_GetB(RGB:value), h, s, l);
	return AHSL:((YUC_SetH(AHSX:h) + YUC_SetS(AHSX:s) + YUC_SetX(AHSX:l)) | YUC_SetA(AHSX:255));
}

stock HSL:operator=(RGBA:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSL(YUC_GetR(RGBA:value), YUC_GetG(RGBA:value), YUC_GetB(RGBA:value), h, s, l);
	return HSL:(YUC_SetH(HSX:h) + YUC_SetS(HSX:s) + YUC_SetX(HSX:l));
}

stock HSLA:operator=(RGBA:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSL(YUC_GetR(RGBA:value), YUC_GetG(RGBA:value), YUC_GetB(RGBA:value), h, s, l);
	return HSLA:((YUC_SetH(HSXA:h) + YUC_SetS(HSXA:s) + YUC_SetX(HSXA:l)) | YUC_SetA(HSXA:YUC_GetA(RGBA:value)));
}

stock AHSL:operator=(RGBA:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSL(YUC_GetR(RGBA:value), YUC_GetG(RGBA:value), YUC_GetB(RGBA:value), h, s, l);
	return AHSL:((YUC_SetH(AHSX:h) + YUC_SetS(AHSX:s) + YUC_SetX(AHSX:l)) | YUC_SetA(AHSX:YUC_GetA(RGBA:value)));
}

stock HSL:operator=(ARGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSL(YUC_GetR(ARGB:value), YUC_GetG(ARGB:value), YUC_GetB(ARGB:value), h, s, l);
	return HSL:(YUC_SetH(HSX:h) + YUC_SetS(HSX:s) + YUC_SetX(HSX:l));
}

stock HSLA:operator=(ARGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSL(YUC_GetR(ARGB:value), YUC_GetG(ARGB:value), YUC_GetB(ARGB:value), h, s, l);
	return HSLA:((YUC_SetH(HSXA:h) + YUC_SetS(HSXA:s) + YUC_SetX(HSXA:l)) | YUC_SetA(HSXA:YUC_GetA(ARGB:value)));
}

stock AHSL:operator=(ARGB:value)
{
	new
		Float:h,
		Float:s,
		Float:l;
	YUC_RGBToHSL(YUC_GetR(ARGB:value), YUC_GetG(ARGB:value), YUC_GetB(ARGB:value), h, s, l);
	return AHSL:((YUC_SetH(AHSX:h) + YUC_SetS(AHSX:s) + YUC_SetX(AHSX:l)) | YUC_SetA(AHSX:YUC_GetA(ARGB:value)));
}
