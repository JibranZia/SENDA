///////////////////////////////////////////////////////////////////////////////
/// \file algorithm.hpp
///   Contains range-based versions of the std algorithms
//
/////////////////////////////////////////////////////////////////////////////
// Copyright 2009 Neil Groves.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.lslboost.org/LICENSE_1_0.txt)
//

// Copyright 2006 Thorsten Ottosen.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.lslboost.org/LICENSE_1_0.txt)
//
// Copyright 2004 Eric Niebler.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.lslboost.org/LICENSE_1_0.txt)

#if defined(_MSC_VER) && _MSC_VER >= 1000
    #pragma once
#endif

#ifndef BOOST_RANGE_NUMERIC_HPP
#define BOOST_RANGE_NUMERIC_HPP

#include <lslboost/config.hpp>
#include <lslboost/assert.hpp>
#include <lslboost/range/begin.hpp>
#include <lslboost/range/end.hpp>
#include <lslboost/range/concepts.hpp>
#include <lslboost/range/distance.hpp>
#include <numeric>


namespace lslboost
{
    template< class SinglePassRange, class Value >
    inline Value accumulate( const SinglePassRange& rng, Value init )
    {
        BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange> ));
        return std::accumulate( lslboost::begin(rng), lslboost::end(rng), init );
    }

    template< class SinglePassRange, class Value, class BinaryOperation >
    inline Value accumulate( const SinglePassRange& rng, Value init, BinaryOperation op )
    {
        BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange> ));
        return std::accumulate( lslboost::begin(rng), lslboost::end(rng), init, op );
    }


    template< class SinglePassRange1, class SinglePassRange2, class Value >
    inline Value inner_product( const SinglePassRange1& rng1, const SinglePassRange2& rng2, Value init )
    {
        BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange1> ));
        BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange2> ));
        BOOST_ASSERT( lslboost::distance(rng2) >= lslboost::distance(rng1) );
        return std::inner_product( lslboost::begin(rng1), lslboost::end(rng1),
            lslboost::begin(rng2), init );
    }

    template< class SinglePassRange1,
              class SinglePassRange2,
              class Value,
              class BinaryOperation1, class BinaryOperation2 >
    inline Value inner_product( const SinglePassRange1& rng1, const SinglePassRange2& rng2,
                                Value init,
                                BinaryOperation1 op1, BinaryOperation2 op2 )
    {
        BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange1> ));
        BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange2> ));
        BOOST_ASSERT( lslboost::distance(rng2) >= lslboost::distance(rng1) );

        return std::inner_product( lslboost::begin(rng1), lslboost::end(rng1),
                                   lslboost::begin(rng2), init, op1, op2 );
    }

    template< class SinglePassRange, class OutputIterator >
    inline OutputIterator partial_sum ( const SinglePassRange& rng,
                                        OutputIterator result )
    {
        BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange> ));
        return std::partial_sum( lslboost::begin(rng), lslboost::end(rng), result );
    }

    template< class SinglePassRange, class OutputIterator, class BinaryOperation >
    inline OutputIterator partial_sum ( const SinglePassRange& rng, OutputIterator result,
                                        BinaryOperation op )
    {
        BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange> ));
        return std::partial_sum( lslboost::begin(rng), lslboost::end(rng), result, op );
    }

    template< class SinglePassRange, class OutputIterator >
    inline OutputIterator adjacent_difference ( const SinglePassRange& rng,
                                                OutputIterator result )
    {
        BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange> ));
        return std::adjacent_difference( lslboost::begin(rng), lslboost::end(rng),
                                         result );
    }

    template< class SinglePassRange, class OutputIterator, class BinaryOperation >
    inline OutputIterator adjacent_difference ( const SinglePassRange& rng,
                                                OutputIterator result,
                                                BinaryOperation op )
    {
        BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<SinglePassRange> ));
        return std::adjacent_difference( lslboost::begin(rng), lslboost::end(rng),
                                         result, op );
    }

}

#endif
