//------------------------------------------------------------------------------
/*
    This file is part of Beast: https://github.com/vinniefalco/Beast
    Copyright 2013, Vinnie Falco <vinnie.falco@gmail.com>

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

    Portions based on SOCI - The C++ Database Access Library: 

    SOCI: http://soci.sourceforge.net/

    This file incorporates work covered by the following copyright
    and permission notice:

    Copyright (C) 2004 Maciej Sobczak, Stephen Hutton, Mateusz Loskot,
    Pawel Aleksander Fedorynski, David Courtney, Rafal Bobrowski,
    Julian Taylor, Henning Basold, Ilia Barahovski, Denis Arnaud,
    Daniel Lidstr�m, Matthieu Kermagoret, Artyom Beilis, Cory Bennett,
    Chris Weed, Michael Davidsaver, Jakub Stachowski, Alex Ott, Rainer Bauer,
    Martin Muenstermann, Philip Pemberton, Eli Green, Frederic Chateau,
    Artyom Tonkikh, Roger Orr, Robert Massaioli, Sergey Nikulov,
    Shridhar Daithankar, S�ren Meyer-Eppler, Mario Valesco.

    Boost Software License - Version 1.0, August 17th, 2003

    Permission is hereby granted, free of charge, to any person or organization
    obtaining a copy of the software and accompanying documentation covered by
    this license (the "Software") to use, reproduce, display, distribute,
    execute, and transmit the Software, and to prepare derivative works of the
    Software, and to permit third-parties to whom the Software is furnished to
    do so, all subject to the following:

    The copyright notices in the Software and this entire statement, including
    the above license grant, this restriction and the following disclaimer,
    must be included in all copies of the Software, in whole or in part, and
    all derivative works of the Software, unless such copies or derivative
    works are solely in the form of machine-executable object code generated by
    a source language processor.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
    SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
    FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/
//==============================================================================

#ifndef BEAST_SQDB_DETAIL_EXCHANGE_TRAITS_H_INCLUDED
#define BEAST_SQDB_DETAIL_EXCHANGE_TRAITS_H_INCLUDED

namespace sqdb
{

namespace detail
{

struct basic_type_tag {};
struct user_type_tag {};

// converts a type to exchange_type
template<typename T>
struct exchange_traits
{
    typedef user_type_tag type_family;

    enum
    {
        x_type = exchange_traits<typename type_conversion<T>::base_type>::x_type
    };
};

template<> struct exchange_traits<bool>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_bool };
};

template<> struct exchange_traits<char>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_char };
};

template<> struct exchange_traits<short>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_short };
};

template<> struct exchange_traits<int>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_int };
};

template<> struct exchange_traits<long>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_long };
};

//template<> struct exchange_traits<boost::int64>
//template<> struct exchange_traits<sqlite3_int64>
template<> struct exchange_traits<int64>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_int64 };
};

template<> struct exchange_traits<unsigned char>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_uchar };
};

template<> struct exchange_traits<unsigned short>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_ushort };
};

template<> struct exchange_traits<unsigned int>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_uint };
};

template<> struct exchange_traits<unsigned long>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_ulong };
};

//template<> struct exchange_traits<boost::uint64>
//template<> struct exchange_traits<sqlite3_uint64>
template<> struct exchange_traits<uint64>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_uint64 };
};

template<> struct exchange_traits<float>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_float };
};

template<> struct exchange_traits<double>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_double };
};

template<> struct exchange_traits<char*>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_cstring };
};

template<> struct exchange_traits<char const*>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_cstring };
};

template<> struct exchange_traits<wchar_t*>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_cwstring };
};

template<> struct exchange_traits<wchar_t const*>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_cwstring };
};

template<> struct exchange_traits<std::string>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_stdstring };
};

template<> struct exchange_traits<std::wstring>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_stdwstring };
};

template<> struct exchange_traits<String>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_beastString };
};

template<> struct exchange_traits<std::tm>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_stdtm };
};

template<> struct exchange_traits<blob>
{
    typedef basic_type_tag type_family;
    enum { x_type = x_blob };
};

}

}

#endif
