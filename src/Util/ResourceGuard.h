/*
 * This file is a part of QComicBook.
 *
 * Copyright (C) 2005-2013 Pawel Stolowski <stolowski@gmail.com>
 *
 * QComicBook is free software; you can redestribute it and/or modify it
 * under terms of GNU General Public License by Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY. See GPL for more details.
 */

#ifndef __RESOURCE_GUARD_H
#define __RESOURCE_GUARD_H

#include <functional>

namespace QComicBook
{

    template <class T, typename F>
        class ResourceGuard
    {
    private:
        T res;
        std::function<F> func;

    public:
        ResourceGuard(T r, F f): res(r), func(f)
        {
        }

        ~ResourceGuard()
        {
            func(res);
        }

        operator T()
        {
            return res;
        }
    };
}

#endif
